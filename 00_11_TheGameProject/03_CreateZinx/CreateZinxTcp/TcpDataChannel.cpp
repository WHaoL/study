#include "TcpDataChannel.h"
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

/*******************************************TcpDataChannel*******************************************/
TcpDataChannel::TcpDataChannel(int _socketFd) : m_socketFd(_socketFd)
{
}

TcpDataChannel::~TcpDataChannel()
{
    /*关闭通信的socketFd*/
    if (m_socketFd >= 0)
    {
        close(m_socketFd);
        m_socketFd = -1;
    }
}

bool TcpDataChannel::Init()
{
    return true;
}
bool TcpDataChannel::ReadFd(std::string &_input)
{
    /***
     * 非阻塞，recv()时返回值为0
     *          确实没数据可读时，返回0
     *          对端关闭时，返回0
    */
    int irecvlen = -1;
    char szBuff[128] = {0};
    bool bRet = false;

    while (1)
    {
        /***
         * 非阻塞方式调用recv()
        */
        irecvlen = recv(m_socketFd, szBuff, sizeof(szBuff), MSG_DONTWAIT);
        if (0 == irecvlen)
        {
            //链接断了：摘除通道
            SetChannelClose();
            break;
        }
        else if (-1 == irecvlen)
        {
            /***
             * recv()是阻塞类型的函数
             * 如果阻塞类型函数强行按照非阻塞去调用，一般会失败，所以要进行出错判断
            */
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                //链接没断，只是没数据了
                break;
            }
            //处理：同：链接断了
            SetChannelClose();
            break;
        }
        else
        {
            _input.append(szBuff, irecvlen);
            bRet = true;
        }
    }
    return bRet;
}
bool TcpDataChannel::WriteFd(std::string &_output)
{
    send(m_socketFd, _output.data(), _output.size(), 0);
    return true;
}
/*把当前数据通道从Kernel中拿掉之前调用，*/
void TcpDataChannel::Fini()
{
    /*关闭通信的socketFd*/
    if (m_socketFd >= 0)
    {
        close(m_socketFd);
        m_socketFd = -1;
    }
}
int TcpDataChannel::GetFd()
{
    return m_socketFd;
}
std::string TcpDataChannel::GetChannelInfo()
{
    return "data_socket" + m_socketFd;
}

/*******************************************TcpListenChannel*******************************************/
/*第二个参数的内存，被该类吸收(该类负责析构)*/
TcpListenChannel::TcpListenChannel(unsigned short _port,
                                   TcpDataChannelFactory *_pfact) : m_port(_port),
                                                                    m_factory(_pfact)
{
}

TcpListenChannel::~TcpListenChannel()
{
    //哪里new，就在哪里delete
    //如果在析构函数里写delete，那么使用时，就不用处理delete了
    if (nullptr != m_factory)
    {
        delete m_factory;
        m_factory = nullptr;
    }
}

bool TcpListenChannel::Init()
{
    /*得到listenFD：socket、bind、listen*/
    bool bRet = false;
    int listenFd = -1;
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFd >= 0)
    {
        /*允许重复绑定：设置listenFd端口复用*/
        struct sockaddr_in stServer;
        stServer.sin_family = AF_INET;
        stServer.sin_addr.s_addr = INADDR_ANY;
        stServer.sin_port = htons(m_port);
        int iflag = 1;
        setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &iflag, sizeof(iflag));
        if (0 == bind(listenFd, (struct sockaddr *)&stServer, sizeof(stServer)))
        {
            if (0 == listen(listenFd, 128))
            {
                m_listenFd = listenFd;
                bRet = true;
            }
            else
            {
                char buf[100];
                sprintf(buf, "%s:%s():%d", __FILE__, __FUNCTION__, __LINE__);
                perror(buf);
            }
        }
        else
        {
            char buf[100];
            sprintf(buf, "%s:%s():%d", __FILE__, __FUNCTION__, __LINE__);
            perror(buf);
        }
    }
    else
    {
        char buf[100];
        sprintf(buf, "%s:%s():%d", __FILE__, __FUNCTION__, __LINE__);
        perror(buf);
    }

    return bRet;
}
bool TcpListenChannel::ReadFd(std::string &_input)
{
    bool bRet = false;
    struct sockaddr_in stClient;
    socklen_t socklen = sizeof(stClient);
    int iDataFd = accept(m_listenFd, (struct sockaddr *)&stClient, &socklen);
    if (iDataFd >= 0)
    {
        /*通信FD建立好了以后，调用Factory创建数据通道*/
        TcpDataChannel *pDataChannel = m_factory->CreateChannel(iDataFd);
        /*把数据通道添加到kernel的epoll树上*/
        bRet = ZinxKernel::Zinx_Add_Channel(*pDataChannel);
    }
    else
    {
        char buf[100];
        sprintf(buf, "%s:%s():%d", __FILE__, __FUNCTION__, __LINE__);
        perror(buf);
    }

    return bRet;
}
bool TcpListenChannel::WriteFd(std::string &_output)
{
    return false;
}
void TcpListenChannel::Fini()
{
    /*关闭监听的socketFd*/
    if (m_listenFd >= 0)
    {
        close(m_listenFd);
        m_listenFd = -1;
    }
}
int TcpListenChannel::GetFd()
{
    return m_listenFd;
}
std::string TcpListenChannel::GetChannelInfo()
{
    return "TCP_LISTEN";
}
AZinxHandler *TcpListenChannel::GetInputNextStage(BytesMsg &_oInput)
{
    return nullptr;
}