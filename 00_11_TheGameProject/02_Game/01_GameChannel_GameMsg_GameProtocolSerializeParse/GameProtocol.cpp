#include "GameProtocol.h"
#include <iostream>
#include "GameMsg.h"
#include "GameChannel.h"
#include "msg.pb.h"
/*
 *协议类 GameProtocol
 */

//输入时通道传来的原始报文（一条原始数据可能含有多条请求）
//返回值是转换后的消息对象MultiMsg
//转换方式是：TCP粘包处理
//    缓存
//    滑动窗口
UserData *GameProtocol::raw2request(std::string _szInput)
{
    MultiMsg *pRet = new MultiMsg();
    szLast.append(_szInput);

    while (1)
    {
        if (szLast.size() < 8)
        {
            break;
        }

        // 在0-3字节中读取消息内容长度
        int iLength = 0;
        iLength |= szLast[0] << 0;
        iLength |= szLast[1] << 8;
        iLength |= szLast[2] << 16;
        iLength |= szLast[3] << 24;
        //在4-7字节读取类型id
        int id = 0;
        id |= szLast[4] << 0;
        id |= szLast[5] << 8;
        id |= szLast[6] << 16;
        id |= szLast[7] << 24;

        // 通过读到的长度，判断后续报文是否合法
        if ((szLast.size() - 8) < iLength)
        {
            //本条报文没有接收完整，啥都不干
            break;
        }
        //构造一条用户请求
        GameMsg *pMsg = new GameMsg((GameMsg::MSG_TYPE)id, szLast.substr(8, iLength));
        pRet->m_Msgs.push_back(pMsg);
        //弹出已经处理的报文
        //szLast = szLast.substr(8 + iLength, szLast.size() - 8 - iLength);
        szLast.erase(0, 8 + iLength);
    }

    // 测试接受数据： TCP粘包处理
    // Tcp客户端发送数据：
    // 08000000010000000801120474657374
    //本程序打印：
    // 18:10:21 发送数据：{08 00 00 00 01 00 00 00 08 01 12 04 74 65 73 74 }
    // <----------------------------------------->
    // recv from 5:08 00 00 00 01 00 00 00 08 01 12 04 74 65 73 74
    // <----------------------------------------->
    // Pid: 1
    // Username: "test"
    // 可以看出：运行正常
     for (auto single : pRet->m_Msgs)
     {
         std::cout << single->pMsg->Utf8DebugString() << std::endl;
     }

    // 测试发送数据
    // 本机发送 "Hello"
    // 客户端收到数据：{07 00 00 00 02 00 00 00 0A 05 48 65 6C 6C 6F }
    // 客户端发送数据：07000000020000000A0548656C6C6F
    // 21:14:53 发送数据：{07 00 00 00 02 00 00 00 0A 05 48 65 6C 6C 6F }
    //<----------------------------------------->
    //recv from 5:07 00 00 00 02 00 00 00 0A 05 48 65 6C 6C 6F 
    //<----------------------------------------->
    //Content: "Hello"
    
    pb::Talk *pmsg = new pb::Talk(); //回复一个聊天信息
    pmsg->set_content("Hello");
    GameMsg *pGameMsg = new GameMsg(GameMsg::MSG_TYPE_CHAT_CONTENT, pmsg);
    ZinxKernel::Zinx_SendOut(*(pGameMsg), *this);

    return pRet;
}
//参数来自业务层Role，参数时Role层待发送的消息
//返回值是转换后的字节流
//发送时，一次只发一条请求
std::string *GameProtocol::response2raw(UserData &_oUserData)
{
    int iLength = 0;
    int id = 0;
    std::string MsgContent;
    auto pret = new std::string();

    GET_REF2DATA(GameMsg, oOutput, _oUserData);
    id = oOutput.enumMsgType;
    MsgContent = oOutput.serialize(); //返回序列化的字符串
    iLength = MsgContent.size();

    // string是空串时，是不能使用下标[]运算符的
    pret->push_back((iLength >> 0) & 0xff);
    pret->push_back((iLength >> 8) & 0xff);
    pret->push_back((iLength >> 16) & 0xff);
    pret->push_back((iLength >> 24) & 0xff);
    pret->push_back((id >> 0) & 0xff);
    pret->push_back((id >> 8) & 0xff);
    pret->push_back((id >> 16) & 0xff);
    pret->push_back((id >> 24) & 0xff);

    pret->append(MsgContent);

    return pret;
}
Irole *GameProtocol::GetMsgProcessor(UserDataMsg &_oUserDataMsg)
{
    return nullptr;
}

// 返回数据发送的通道
Ichannel *GameProtocol::GetMsgSender(BytesMsg &_oBytes)
{
    return m_channel;
}
