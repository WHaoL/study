#include "GameChannel.h"
#include "GameProtocol.h"
#include "GameRole.h"
/*
 *TcpChannel类
 */
GameChannel::GameChannel(int fd) : ZinxTcpData{fd} {}

/*
 *我们在Channel的析构函数中，摘除框架中对应的Protocol，并释放堆区
 *在Protocol的析构函数中，摘除框架中对应的Role，并释放堆区
 */
GameChannel::~GameChannel()
{
    if (nullptr != m_protocol)
    {
        ZinxKernel::Zinx_Del_Proto(*m_protocol); /*从框架中摘除*/
        delete m_protocol;                       /*释放堆区*/
        m_protocol = nullptr;
    }
}
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
    // 创建role对象
    GameRole *porole = new GameRole();

    // 绑定 tcp channel和protocol(相互绑定)
    pochannel->m_protocol = poprotocol;
    poprotocol->m_channel = pochannel;
    // 绑定protocol和role(相互绑定)
    poprotocol->m_role = porole;
    porole->m_protocol = poprotocol;

    // 将protocol、role对象添加到Kernel
    ZinxKernel::Zinx_Add_Proto(*poprotocol);
    ZinxKernel::Zinx_Add_Role(*porole);

    return pochannel;
}
