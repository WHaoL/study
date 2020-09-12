#ifndef __GAMEMSG_H__
#define __GAMEMSG_H__
#include <zinx.h>
#include <google/protobuf/message.h>
#include <list>
/*
 *Protocol向Role传递的数据类型
 *一条消息
 */
class GameMsg : public UserData
{
public:
    google::protobuf::Message *pMsg = nullptr;
    //消息类型
    enum MSG_TYPE
    {
        MSG_TYPE_LOGIN_IN_NAME = 1,
        MSG_TYPE_CHAT_CONTENT = 2,
        MSG_TYPE_NEW_POSITION = 3,
        MSG_TYPE_BROADCAST = 200,
        MSG_TYPE_LOGOFF_ID_NAME = 201,
        MSG_TYPE_SURROUND_POSITION = 202
    } enumMsgType;

public:
    //构造函数1：已知消息内容，创建消息对象
    GameMsg(MSG_TYPE _type, google::protobuf::Message *_pMsg);
    //构造函数2：将字节流内容，转换成消息结构并创建消息对象
    GameMsg(MSG_TYPE _type, std::string _stream);

    //序列化本消息，转换为字节流
    std::string serialize();

    virtual ~GameMsg();
};

/*
 *Protocol向Role传递的数据类型
 *多条消息
 */
class MultiMsg : public UserData
{
public:
    std::list<GameMsg *> m_Msgs;
};

#endif