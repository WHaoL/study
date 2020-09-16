#include "GameRole.h"
#include "GameMsg.h"
#include "AOIWorld.h"
#include <iostream>
using std::cout;
using std::endl;
#include "msg.pb.h"
#include "GameProtocol.h"
#include "GameChannel.h"
#include <algorithm>
#include <random>
#include "ZinxTimer.h"
#include "RandomName.h"

RandomName random_name; //该全局对象：负责随机生成名字

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
/*向周围玩家，发送聊天广播*/
GameMsg *GameRole::CreateTalkBroadCast(std::string _content)
{
    pb::BroadCast *poBroadcast = new pb::BroadCast();
    poBroadcast->set_pid(iPid);
    poBroadcast->set_username(szName);
    poBroadcast->set_tp(1);
    poBroadcast->set_content(_content);
    GameMsg *pRet = new GameMsg(GameMsg::MSG_TYPE_BROADCAST, poBroadcast);
    return pRet;
}

void GameRole::ProcTalkMsg(std::string _content) //广播聊天消息,参数时聊天内容
{
    //聊天内容：发送给所有人
    std::list<Irole *> &all_Role_List = ZinxKernel::Zinx_GetAllRole(); /*发给所有人*/
    for (auto pRole : all_Role_List)
    {
        GameMsg *pmsg = CreateTalkBroadCast(_content); /*封装聊天消息为GameMsg*/

        GameRole *pGameRole = dynamic_cast<GameRole *>(pRole);
        ZinxKernel::Zinx_SendOut(*(pmsg), *(pGameRole->m_protocol));
    }
}
void GameRole::ProcMoveMsg(float _x, float _y, float _z, float _v) //发送新位置
{
    /*1、视野切换(跨网格处理)*/
    //获取原来的邻居，得到集合S1
    std::list<Player *> s1 = world.GetSurrendPlayers(this);
    //更新坐标(先从旧格子中摘除，然后更新坐标，最后添加到新格子中)，获取新的邻居得到集合S2
    world.DelPlayer(this);
    x = _x;
    y = _y;
    z = _z;
    v = _v;
    world.AddPlayer(this);
    //获取新的邻居，得到集合S2
    std::list<Player *> s2 = world.GetSurrendPlayers(this);
    //视野出现
    //遍历S2,若某些元素不属于S2,则证明这些元素是我们的新邻居，向它们发送202号信号，让彼此能看到彼此，
    for (std::list<Player *>::iterator itr_s2_single_player = s2.begin(); itr_s2_single_player != s2.end(); ++itr_s2_single_player)
    {
        if (s1.end() == find(s1.begin(), s1.end(), *(itr_s2_single_player)))
        {
            //视野出现,this和传进来的Role相互能看到彼此
            ViewAppear(dynamic_cast<GameRole *>(*(itr_s2_single_player)));
        }
    }
    //视野消失
    //遍历S1,若某些元素不属于S2,则证明这些元素使我们的视野之外的旧邻居，向它们发送201信号，让彼此看不到彼此
    for (std::list<Player *>::iterator itr_s1_single_player = s1.begin(); itr_s1_single_player != s1.end(); ++itr_s1_single_player)
    {
        if (s2.end() == find(s2.begin(), s2.end(), *(itr_s1_single_player)))
        {
            //视野消失,this和传进来的Role相互不能看到彼此
            ViewLost(dynamic_cast<GameRole *>(*(itr_s1_single_player)));
        }
    }
    /*2、广播新位置给周围玩家*/
    //2.1 取出新位置
    //遍历周围玩家，发送
    //向周围玩家，发送自己的新位置
    std::list<Player *> Sur_List = world.GetSurrendPlayers(this);
    for (Player *single : Sur_List)
    {
        //2.2 组成待发送的报文
        pb::BroadCast *pmsg = new pb::BroadCast();
        pb::Position *pPos = pmsg->mutable_p();
        pPos->set_x(_x);
        pPos->set_y(_y);
        pPos->set_z(_z);
        pPos->set_v(_v);
        pmsg->set_pid(iPid);
        pmsg->set_username(szName);
        pmsg->set_tp(4);

        //通过别人的Protocol层，把数据发给他们(各个玩家)
        GameRole *poOtherRole = dynamic_cast<GameRole *>(single);
        ZinxKernel::Zinx_SendOut(*(new GameMsg(GameMsg::MSG_TYPE_BROADCAST, pmsg)), *(poOtherRole->m_protocol));
    }
}

void GameRole::ViewAppear(GameRole *_pRole) //视野出现,this和传进来的Role相互能看到彼此
{
    // _pRole是新出现的邻居

    //向自己发送新邻居的位置 200号消息
    GameMsg *poNewPlayerPos = _pRole->CreateSelfPosition(); //新邻居的位置
    ZinxKernel::Zinx_SendOut(*poNewPlayerPos, *m_protocol); //把新邻居的位置发给自己

    //向这个新邻居发送 this的位置 200号消息
    GameMsg *poThisPlayerPos = CreateSelfPosition();
    ZinxKernel::Zinx_SendOut(*poThisPlayerPos, *(_pRole->m_protocol));
}
void GameRole::ViewLost(GameRole *_pRole) //视野消失,this和传进来的Role相互不能看到彼此
{
    // 向自己发送消息：拿掉我对旧邻居的视野 (旧邻居的201号消息)
    GameMsg *poOldPlayerPosOff = _pRole->CreateIDNameLogoff();
    ZinxKernel::Zinx_SendOut(*poOldPlayerPosOff, *m_protocol);
    // 向旧邻居发消息：拿掉旧邻居对我的视野 (本玩家的201号消息)
    GameMsg *poThisPlayerPosOff = CreateIDNameLogoff();
    ZinxKernel::Zinx_SendOut(*poThisPlayerPosOff, *(_pRole->m_protocol));
}

//随机数引擎，产生随机数
static std::default_random_engine random_engine(time(NULL));
/*因为构造函数没有返回值，不方便做出错判断
 *比如：打开文件，写文件...(不要在构造函数中写)
 * **/
GameRole::GameRole()
{
    x = 100 + random_engine() % 50;
    y = 0; /*在水平面上*/
    z = 100 + random_engine() % 50;
    szName = random_name.GetName(); //生成名字
}

GameRole::~GameRole()
{
    random_name.Release(szName); //还名字
}

/*创建 退出程序定时器 类 */
class ExitTimer : public TimeOutProcess
{
    virtual void Proc()
    {
        ZinxKernel::Zinx_Exit();
    }
    virtual int GetTimeSecond() // 返回定时时间:20S
    {
        return 20;
    }
};
static ExitTimer g_exit_timer; //创建 退出定时器 单例

/*public Irole*/
bool GameRole::Init()
{
    //判断是否是第一个玩家 --> 关闭：定时器
    if (ZinxKernel::Zinx_GetAllRole().size() <= 0)
    {
        //关闭：退出定时器
        TimeOutManager::GetInstance().DelTask(&g_exit_timer);
    }

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
        GameMsg *posurplayer = CreateSurPlayers();
        ZinxKernel::Zinx_SendOut(*posurplayer, *m_protocol);
        /*向周围玩家，发送自己的位置*/
        std::list<Player *> Sur_List = world.GetSurrendPlayers(this);
        for (Player *single : Sur_List)
        {
            GameMsg *poselfPosition = CreateSelfPosition();
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
    //protocol -->  role 发送的MultiMsg(GameMsg)数据
    GET_REF2DATA(MultiMsg, userdata, _poUserData);

    for (GameMsg *&single : userdata.m_Msgs)
    {
        // 测试：打印消息内容，打印收到的数据
        cout << "Message Type: " << single->enumMsgType << endl;
        cout << single->pMsg->Utf8DebugString() << endl;

        pb::Position *NewPos = dynamic_cast<pb::Position *>(single->pMsg);
        switch (single->enumMsgType)
        {
        case GameMsg::MSG_TYPE_CHAT_CONTENT: //广播：聊天内容
            ProcTalkMsg(dynamic_cast<pb::Talk *>(single->pMsg)->content());
            break;
        case GameMsg::MSG_TYPE_NEW_POSITION: //向周围玩家发送自己的新位置：移动
            ProcMoveMsg(NewPos->x(), NewPos->y(), NewPos->z(), NewPos->v());
            break;
        default:
            break;
        }
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

    /*玩家全部退出后，20s内无新连接，服务器退出*/
    //判断是否是最后一个玩家 --> 起定时器
    if (ZinxKernel::Zinx_GetAllRole().size() <= 1)
    {
        //启动：退出定时器
        TimeOutManager::GetInstance().AddTask(&g_exit_timer);
    }
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