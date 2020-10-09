#include "ZinxKernel.h"
#include <sys/epoll.h>
#include <unistd.h>
#include <iostream>
#include "IChannel.h"

ZinxKernel ZinxKernel::kernel; //定义

ZinxKernel::ZinxKernel()
{
    //创建epoll树
    int fd = epoll_create(1);
    if (fd >= 0)
    {
        m_EpollFd = fd;
    }
}
ZinxKernel::~ZinxKernel()
{
    //销毁epoll树
    if (-1 != m_EpollFd)
    {
        close(m_EpollFd);
        m_EpollFd = -1;
    }
}

void ZinxKernel::run()
{
    //1 等输入(IO多路复用)(epoll)
    //2 调用通道的读取(或写出)函数
    //3 回显到标准输出

    //反应堆模型
    //先让epoll树监测input，
    //    有input时，读入数据，并调用对应的处理函数对数据进行处理
    //如果有数据需要output，让epoll把监测input改为监测output，
    //    可写时，调用对应的处理函数发送数据
    //让epoll把监测output改为监测input

    while (1)
    {
        struct epoll_event ar_stEvents[50];
        int len = sizeof(ar_stEvents) / sizeof(ar_stEvents[0]);
        int ready_count = epoll_wait(m_EpollFd, ar_stEvents, len, -1);
        if (0 == ready_count)
        {
            if (EINTR == errno) // Error number interrupt
            {
                continue; //如果是被信号打断了
            }
        }
        for (int i = 0; i < ready_count; ++i)
        {
            if (EPOLLIN == (ar_stEvents[i].events & EPOLLIN)) //监测到有input
            {
                //处理外部输入的数据
                //触发 处理责任链
                IChannel *pchannel = static_cast<IChannel *>(ar_stEvents[i].data.ptr);
                System_IO_Direction_Msg dir(System_IO_Direction_Msg::IO_IN);
                pchannel->handle(&dir);
            }
            if (EPOLLOUT == (ar_stEvents[i].events & EPOLLOUT)) //监测到output可用
            {
                //向外输出数据
                //把缓存区数据，发送出去
                //2、把监测input|output改为监测input
                IChannel *pchannel = static_cast<IChannel *>(ar_stEvents[i].data.ptr);
                pchannel->flushout();
                ModChannel_DelOut(pchannel);
            }
        }
    }
}

void ZinxKernel::AddChannel(IChannel *_pChannel) //把通道添加到epoll
{
    if (true == _pChannel->Init())
    {
        //将参数和文件描述符0 关联起来 epoll_ctl
        struct epoll_event stEvent;
        stEvent.events = EPOLLIN;
        stEvent.data.ptr = _pChannel;
        epoll_ctl(m_EpollFd, EPOLL_CTL_ADD, _pChannel->GetFd(), &stEvent);
    }
}
void ZinxKernel::DelChannel(IChannel *_pChannel) //把通道从epoll移除
{
    epoll_ctl(m_EpollFd, EPOLL_CTL_DEL, _pChannel->GetFd(), nullptr);
    _pChannel->Fini(); //初始化和去初始化，顺序相反
}
void ZinxKernel::ModChannel_AddOut(IChannel *_pChannel) //向epoll，给通道添加输出的监听
{
    struct epoll_event stEvent;
    stEvent.events = EPOLLIN | EPOLLOUT;
    stEvent.data.ptr = _pChannel;
    epoll_ctl(m_EpollFd, EPOLL_CTL_MOD, _pChannel->GetFd(), &stEvent);
}
void ZinxKernel::ModChannel_DelOut(IChannel *_pChannel) //从epoll，移除 通道输出监听
{
    struct epoll_event stEvent;
    stEvent.events = EPOLLIN;
    stEvent.data.ptr = _pChannel;
    epoll_ctl(m_EpollFd, EPOLL_CTL_MOD, _pChannel->GetFd(), &stEvent);
}
void ZinxKernel::Zinx_sendout(std::string _output, IChannel *_channel)
{
    System_IO_Direction_Msg iodir(System_IO_Direction_Msg::IO_OUT);
    ByteMsg byte(iodir,_output);
    _channel->handle(&byte);
}