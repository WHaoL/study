#include "FIFOChannel.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

FIFOChannel::FIFOChannel(std::string _fifoName, bool _isRead) : m_fifo_name(_fifoName),
                                                                  isRead(_isRead)
{
}
FIFOChannel::~FIFOChannel()
{
}

bool FIFOChannel::Init()
{
    bool boolRet = false;
    
    //打开文件
    int flag = O_RDONLY;
    if (false == isRead)
    {
        flag = O_WRONLY;
    }

    // open是一个阻塞函数,设置为非阻塞
    // int fd = open(m_fifo_name.c_str(), flag );
    int fd = open(m_fifo_name.c_str(), (flag | O_NONBLOCK));
    if (fd >= 0)
    {
        m_fifo_fd = fd;
        boolRet = true;
    }
    return boolRet;
}
void FIFOChannel::Fini()
{
    //关闭文件
    if (m_fifo_fd >= 0)
    {
        close(m_fifo_fd);
        m_fifo_fd = -1;
    }
}
std::string FIFOChannel::ReadFd()
{
    char ibuf[1024] = {0};
    int ilen = read(m_fifo_fd, ibuf, sizeof(ibuf));
    return std::string(ibuf, ilen);
}
void FIFOChannel::WriteFd(std::string _output)
{
    char *pout = (char *)malloc(_output.size());
    _output.copy(pout, _output.size(), 0);
    write(m_fifo_fd, pout, _output.size());
    free(pout);
}
int FIFOChannel::GetFd()
{
    return m_fifo_fd;
}
ZinxHandler * FIFOChannel::GetInputNextStage(ByteMsg *_byte)
{
    return m_fifo_out_channel;
}