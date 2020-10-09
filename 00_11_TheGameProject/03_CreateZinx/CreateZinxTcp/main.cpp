/***
 * 测试TCPChannel
*/

#include "TcpDataChannel.h"
#include "zinx.h"
class Echo : public AZinxHandler
{
    virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput)
    {
        GET_REF2DATA(BytesMsg, input, _oInput);
        Ichannel *channel = ZinxKernel::Zinx_GetChannel_ByInfo(input.szInfo);
        ZinxKernel::Zinx_SendOut(input.szData, *channel);
        return nullptr;
    }

    virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg)
    {
        return nullptr;
    }
} echo;

class myTcpDataChannel : public TcpDataChannel
{
public:
    myTcpDataChannel(int _fd) : TcpDataChannel(_fd)
    {

    }
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput)
    {
        return &echo;
    }
};
class myfact : public TcpDataChannelFactory
{
public:
    TcpDataChannel *CreateChannel(int _fd)
    {
        new myTcpDataChannel(_fd);
    }
};

int main()
{
    ZinxKernel::ZinxKernelInit();
    ZinxKernel::Zinx_Add_Channel(*(new TcpListenChannel(23333, new myfact())));
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();
    return 0;
}