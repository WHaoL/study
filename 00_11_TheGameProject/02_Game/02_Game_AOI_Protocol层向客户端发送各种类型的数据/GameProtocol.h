#ifndef __GAMEPROTOCOL_H__
#define __GAMEPROTOCOL_H__
#include <zinx.h>

// #include "GameChannel.h" 不要在两个.h头文件中相互引用，会导致循环引用
class GameChannel;
class GameRole;

/*
 *协议类 GameProtocol
 */
class GameProtocol : public Iprotocol
{
public:
    GameProtocol();
    virtual ~GameProtocol();

public:
    virtual UserData *raw2request(std::string _szInput) override;
    virtual std::string *response2raw(UserData &_oUserData) override;
    virtual Irole *GetMsgProcessor(UserDataMsg &_oUserDataMsg) override;
    virtual Ichannel *GetMsgSender(BytesMsg &_oBytes) override;

public:
    // 缓存上次未处理的报文
    std::string szLast;
    // Protocol和Channel相互绑定
    GameChannel *m_channel = nullptr;
    GameRole *m_role = nullptr;
};
#endif