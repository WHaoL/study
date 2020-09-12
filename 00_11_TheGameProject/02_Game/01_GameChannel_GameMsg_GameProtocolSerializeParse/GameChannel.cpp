#include "GameChannel.h"
#include "GameProtocol.h"
/*
 *TcpChannel类
 */
GameChannel::GameChannel(int fd) : ZinxTcpData{fd} {}
GameChannel::~GameChannel() {}
// 返回协议对象
AZinxHandler *GameChannel::GetInputNextStage(BytesMsg &_oInput)
{
    return m_protocol;
}

/*
 *工厂类，用来生产GameChannel对象
 */
ZinxTcpData *GameConnFact::CreateTcpDataChannel(int _fd)
{
    // 创建tcp channel对象
    GameChannel *pochannel = new GameChannel(_fd);
    // 创建protocol对象
    GameProtocol *poprotocol = new GameProtocol();
    // 绑定 tcp channel和protocol(相互绑定)
    pochannel->m_protocol = poprotocol;
    poprotocol->m_channel = pochannel;
    // 将协议对象添加到Kernel
    ZinxKernel::Zinx_Add_Proto(*poprotocol);
    return pochannel;
}
