#include "GameMsg.h"
#include "msg.pb.h"
#include <google/protobuf/message.h>

//构造函数1：已知消息内容，创建消息对象
GameMsg::GameMsg(MSG_TYPE _type, google::protobuf::Message *_pMsg) : enumMsgType(_type), pMsg(_pMsg) {}
//构造函数2：将字节流内容，转换成消息结构并创建消息对象
GameMsg::GameMsg(MSG_TYPE _type, std::string _stream) : enumMsgType(_type)
{
    //通过简单工厂，构造具体的消息对象
    switch (enumMsgType)
    {
    case GameMsg::MSG_TYPE_LOGIN_IN_NAME:
        pMsg = new pb::SyncPid();
        break;
    case GameMsg::MSG_TYPE_CHAT_CONTENT:
        pMsg = new pb::Talk();
        break;
    case GameMsg::MSG_TYPE_NEW_POSITION:
        pMsg = new pb::Position();
        break;
    case GameMsg::MSG_TYPE_BROADCAST:
        pMsg = new pb::BroadCast();
        break;
    case GameMsg::MSG_TYPE_LOGOFF_ID_NAME:
        pMsg = new pb::SyncPid();
        break;
    case GameMsg::MSG_TYPE_SURROUND_POSITION:
        pMsg = new pb::SyncPlayers();
        break;
    default:
        break;
    }

    // 将参数_stream解析成消息内容
    pMsg->ParseFromString(_stream);
}

//序列化本消息，转换为十六进制字节流
std::string GameMsg::serialize()
{
    std::string ret;
    pMsg->SerializeToString(&ret);
    return ret;
}

GameMsg::~GameMsg()
{
}