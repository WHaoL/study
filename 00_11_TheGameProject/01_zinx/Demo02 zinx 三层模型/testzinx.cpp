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

int main()
{
    //1-初始化框架
    ZinxKernel::ZinxKernelInit();

    //将通道类添加到对象
    ZinxKernel::Zinx_Add_Channel(*(new StdInChannel()));
    ZinxKernel::Zinx_Add_Channel(*(new StdOutChannel()));
    //添加TCP监听通道
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(51111,new myTcpFactory())));
    //添加回显对象、日期前缀对象、输出控制对象
    ZinxKernel::Zinx_Add_Role(*(new EchoRole()));
    ZinxKernel::Zinx_Add_Role(*(new DatePreRole()));
    ZinxKernel::Zinx_Add_Role(*(new OutputCtrlRole()));

    //运行框架
    ZinxKernel::Zinx_Run();

    //结束
    ZinxKernel::ZinxKernelFini();

    return 0;
}