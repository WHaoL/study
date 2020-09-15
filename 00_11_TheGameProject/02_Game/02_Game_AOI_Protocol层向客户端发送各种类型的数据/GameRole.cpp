#include "GameRole.h"
#include "GameMsg.h"
#include "AOIWorld.h"
#include <iostream>
using std::cout;
using std::endl;
#include "msg.pb.h"
#include "GameProtocol.h"
#include "GameChannel.h"
/*
 *决策类 
 */

/*只有一张地图
 *游戏世界中，坐标的范围(横竖)都是0-400 
 * */

/*创建唯一游戏世界全局对象***/
/*让world只在本文件(Role 决策层)访问，加上static限制对象的作用域为本文件*/
static AOIWorld world(0, 400, 0, 400, 20, 20);

/*向自己发送 自己的ID和Name：封装ID和Name为一个数据对象，并返回*/
GameMsg *GameRole::CreateIDNameLogin()
{
    /*构造好一个protobuf类型的消息，然后组装成GameMsg对象*/
    /*ID和Name*/
    pb::SyncPid *pmsg = new pb::SyncPid();
    pmsg->set_username(szName);
    pmsg->set_pid(iPid);
    GameMsg *pRet = new GameMsg(GameMsg::MSG_TYPE_LOGIN_IN_NAME, pmsg);
    return pRet;
}
/*向自己发送周围玩家：封装周围玩家为一个数据对象，并返回*/
GameMsg *GameRole::CreateSurPlayers()
{
    pb::SyncPlayers *pmsg = new pb::SyncPlayers();
    std::list<Player *> pSurList = world.GetSurrendPlayers(this); /*获取周围玩家*/
    for (Player *single : pSurList)                               /*循环完毕：把所有周围玩家都放到了pmsg中了*/
    {
        /*每循环一次：添加一个Player到SyncPlayer*/

        /*拿到protobuf框架中，数组类型SyncPlayers，的每个数组元素(Player)的指针，
         *利用这个数组元素(Player)的指针，往里面添加Player相关信息
         */
        pb::Player *pPlayer = pmsg->add_ps();
        /*往protobuf中的repeated类型(数组类型)，设置数组元素
         *调用add_xxx()
         *调用后，相当于添加一个数组成员,并同时返回一个数组元素的指针
         *利用这个指针，设置这个数组元素的数据即可
         * */

        GameRole *pRole = dynamic_cast<GameRole *>(single); /*转为子类，获取玩家的信息*/

        pPlayer->set_pid(pRole->iPid); //添加子消息Player的一般信息
        pPlayer->set_username(pRole->szName);
        pb::Position *pPosotion = pPlayer->mutable_p(); //添加子消息Player的子消息(Position)的信息
        /*在protobuf中mutable_XXX()，会把子消息挂到父消息里，并返回子消息的指针*/
        /*设置protobuf框架汇总的，复合类型(即一个类，包含了子类)
         *调用mutable_xxx()
         *调用后，会向当前消息添加子消息，并返回子消息的指针
         *利用这个指针，设置这个子消息的数据即可
         */
        pPosotion->set_x(pRole->x);
        pPosotion->set_y(pRole->y);
        pPosotion->set_z(pRole->z);
        pPosotion->set_v(pRole->v);
    }
    GameMsg *pret = new GameMsg(GameMsg::MSG_TYPE_SURROUND_POSITION, pmsg);
    return pret;
}
/*向周围玩家，发送自己的位置：封装自己的数据为一个数据对象，并返回*/
GameMsg *GameRole::CreateSelfPosition()
{
    pb::BroadCast *pmsg = new pb::BroadCast();
    pmsg->set_pid(iPid);
    pmsg->set_username(szName);
    pmsg->set_tp(2);

    pb::Position *pPosition = pmsg->mutable_p();
    pPosition->set_x(x);
    pPosition->set_y(y);
    pPosition->set_z(z);
    pPosition->set_v(v);

    GameMsg *pRet = new GameMsg(GameMsg::MSG_TYPE_BROADCAST, pmsg);
    return pRet;
}
/*向周围玩家，发送下线通知：封装ID和Name为一个数据对象，并返回*/
GameMsg *GameRole::CreateIDNameLogoff()
{
    /*构造好一个protobuf类型的消息，然后组装成GameMsg对象*/
    /*ID和Name*/
    pb::SyncPid *pmsg = new pb::SyncPid();
    pmsg->set_username(szName);
    pmsg->set_pid(iPid);
    GameMsg *pRet = new GameMsg(GameMsg::MSG_TYPE_LOGOFF_ID_NAME, pmsg);
    return pRet;
}

/*因为构造函数没有返回值，不方便做出错判断
 *比如：打开文件，写文件...(不要在构造函数中写)
 * **/
GameRole::GameRole()
{
    x = 100;
    y = 0; /*在水平面上*/
    z = 100;
    szName = "渣渣辉";
}
GameRole::~GameRole()
{
}
/*public Irole*/
bool GameRole::Init()
{
    bool bRet = false;                     /*标志位*/
    bRet = world.AddPlayer(this);          /*把该玩家加入游戏世界*/
    iPid = m_protocol->m_channel->GetFd(); /*设置当前玩家ID为当前，连接的fd*/
    //szName = "Tom";                        /*玩家姓名,先固定，后面再更改*/

    if (true == bRet)
    {
        /*向客户端(自己)，发送自己的ID和名称*/
        GameMsg *poLogin = CreateIDNameLogin();
        ZinxKernel::Zinx_SendOut(*poLogin, *m_protocol);
        /*向自己，发送周围玩家的位置*/
        GameMsg * posurplayer = CreateSurPlayers();
        ZinxKernel::Zinx_SendOut(*posurplayer, *m_protocol);
        /*向周围玩家，发送自己的位置*/
        std::list<Player *> Sur_List = world.GetSurrendPlayers(this);
        for (Player *single : Sur_List)
        {
            GameMsg * poselfPosition = CreateSelfPosition();
            /*通过别人的Protocol层，把数据发给他们(各个玩家)*/
            GameRole *poOtherRole = dynamic_cast<GameRole *>(single);
            ZinxKernel::Zinx_SendOut(*poselfPosition, *(poOtherRole->m_protocol));
        }
    }

    return bRet;
}
/*public Irole*/
//处理游戏相关的用户请求
UserData *GameRole::ProcMsg(UserData &_poUserData)
{
    // 测试：protocol -->  role 发送的MultiMsg(GameMsg)数据
    GET_REF2DATA(MultiMsg, userdata, _poUserData);
    for (GameMsg *&single : userdata.m_Msgs)
    {
        cout << "Message Type: " << single->enumMsgType << endl;
        cout << single->pMsg->Utf8DebugString() << endl;
    }

    //不需要下一个处理环节，就返回nullptr
    return nullptr;
}
/*public Irole*/
/*
 *我们在Channel的析构函数中，摘除框架中对应的Protocol，并释放堆区
 *在Protocol的析构函数中，摘除框架中对应的Role，并释放堆区
 */
void GameRole::Fini()
{
    /*向周围玩家发送下线消息*/
    std::list<Player *> Sur_List = world.GetSurrendPlayers(this);
    for (Player *single : Sur_List)
    {
        GameMsg *pmsg = CreateIDNameLogoff();
        /*通过别人的Protocol层，把数据发给他们(各个玩家)*/
        GameRole *poOtherRole = dynamic_cast<GameRole *>(single);
        ZinxKernel::Zinx_SendOut(*(pmsg), *(poOtherRole->m_protocol));
    }

    /*把该玩家从游戏世界摘除*/
    world.DelPlayer(this);
}
// public Player
int GameRole::GetX()
{
    return (int)x;
}
// public Player
int GameRole::GetY()
{
    return (int)z;
}