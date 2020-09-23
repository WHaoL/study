#ifndef __ZINXKERNEL_H__
#define __ZINXKERNEL_H__
#include <list>
class IChannel;
class StdinChannel;
class ZinxKernel //全局只有一个Kernel
{
private: //单例
    ZinxKernel();
    virtual ~ZinxKernel();
    static ZinxKernel kernel; //饿汉模式
public:
    void run();
    void AddChannel(IChannel *_pChannel);        //把通道添加到epoll
    void DelChannel(IChannel *_pChannel);        //把通道从epoll移除
    void ModChannel_AddOut(IChannel *_pChannel); //向epoll，给通道添加输出的监听
    void ModChannel_DelOut(IChannel *_pChannel); //从epoll，移除 通道输出监听

    static ZinxKernel &GetInstance()
    {
        return kernel;
    }

private:
    std::list<IChannel *> m_channel_list; //Channel
    int m_EpollFd = -1;                   //epoll树
};
#endif