#include <zinx.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include "CommandRecognition.h"
#include "Roles.h"
#include "StdInOutChannel.h"
#include <ZinxTCP.h>
#include "ZinxTimer.h"

/*
 *超时任务类
 * 本类：处理具体的超时事件
 */
class timerhello : public TimeOutProcess
{
    virtual void Proc()
    {
        Ichannel *poChannel = ZinxKernel::Zinx_GetChannel_ByInfo("stdout");
        std::string outputData = "Hello world";
        ZinxKernel::Zinx_SendOut(outputData, *poChannel);
    }
    virtual int GetTimeSecond()
    {
        return 3;
    }
};
/*
 *超时任务类
 * 本类：处理具体的超时事件
 */
class timerbye : public TimeOutProcess
{
    virtual void Proc()
    {
        Ichannel *poChannel = ZinxKernel::Zinx_GetChannel_ByInfo("stdout");
        std::string outputData = "bye";
        ZinxKernel::Zinx_SendOut(outputData, *poChannel);
        TimeOutManager::GetInstance().DelTask(this);
    }
    virtual int GetTimeSecond()
    {
        return 5;
    }
};



int main()
{
    //1-初始化框架
    ZinxKernel::ZinxKernelInit();

    // 添加定时任务到定时器管理模块
    TimeOutManager::GetInstance().AddTask(new timerhello());
    TimeOutManager::GetInstance().AddTask(new timerbye());

    //将通道类添加到对象
    ZinxKernel::Zinx_Add_Channel(*(new StdInChannel()));
    ZinxKernel::Zinx_Add_Channel(*(new StdOutChannel()));
    //添加定时器通道
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTimerChannel()));
    //添加回显对象、日期前缀对象、输出控制对象
    ZinxKernel::Zinx_Add_Role(*(new EchoRole()));
    ZinxKernel::Zinx_Add_Role(*(new DatePreRole()));
    ZinxKernel::Zinx_Add_Role(*(new OutputCtrlRole()));
    //添加TCP监听通道
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(51111, new myTcpFactory())));

    //运行框架
    ZinxKernel::Zinx_Run();

    //结束
    ZinxKernel::ZinxKernelFini();

    return 0;
}