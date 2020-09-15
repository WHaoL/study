#ifndef __GAMECHANNEL_H__
#define __GAMECHANNEL_H__
#include <zinx.h>
#include <ZinxTCP.h>
#include "GameProtocol.h"
/*
 *TcpChannel类
 */
class GameChannel : public ZinxTcpData
{
public:
    GameChannel(int fd);
    virtual ~GameChannel();

public:
    // 返回协议对象
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;

public:
    // Channel和Protocol绑定在一起，一一对应
    // 在GameChannel.cpp中的GameConnFact::CreateTcpDataChannel()进行实现
    GameProtocol *m_protocol = nullptr;
};

/*
 *工厂类，用来生产GameChannel对象
 */
class GameConnFact : public IZinxTcpConnFact
{
public:
    // 创建GameChannel的同时，创建GameProtocol，然后把二者绑定在一起
    // 将协议对象添加到Kernel
    ZinxTcpData *CreateTcpDataChannel(int _fd) override;
};
#endif