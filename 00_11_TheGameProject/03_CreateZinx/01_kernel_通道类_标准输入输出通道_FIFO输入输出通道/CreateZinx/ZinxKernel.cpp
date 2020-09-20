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
    while (1)
    {
        struct epoll_event ar_stEvents[20];
        int ready_count = epoll_wait(m_EpollFd, ar_stEvents, 20, -1);
        if (0 == ready_count)
        {
            if (EINTR == errno) // Error number interrupt
            {
                //如果是被信号打断了
                continue;
            }
        }
        for (int i = 0; i < ready_count; ++i)
        {
            if (0 != (ar_stEvents[i].events & EPOLLIN))
            {
                //需要处理外部输入的数据
                /*1.读出数据*/
                IChannel *pchannel = static_cast<IChannel *>(ar_stEvents[i].data.ptr);
                std::string content = pchannel->ReadFd();
                /*2.处理数据*/
                pchannel->Data_Process(content);
            }
            if (0 != (ar_stEvents[i].events & EPOLLOUT))
            {
                //向外输出数据
                IChannel *pchannel = static_cast<IChannel *>(ar_stEvents[i].data.ptr);
                pchannel->flushout();
                //删掉输出方向的epoll监听
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
    _pChannel->Fini();//初始化和去初始化，顺序相反
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