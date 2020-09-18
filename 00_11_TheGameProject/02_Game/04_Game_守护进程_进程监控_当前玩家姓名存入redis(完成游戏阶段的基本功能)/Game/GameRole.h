#ifndef __GAMEROLE_H__
#define __GAMEROLE_H__
#include <zinx.h>
#include "AOIWorld.h"
//头文件中需要用到别的类的时候，能不包含头文件(不用类内成员时)，就不包含头文件
//防止头文件循环引用 循环依赖
class GameProtocol;
class GameMsg;
/*
 *决策类 
 */
class GameRole : public Irole, public Player
{
public:
    GameRole();
    virtual ~GameRole();

public:
    // public Irole
    virtual bool Init() override;
    virtual UserData *ProcMsg(UserData &_poUserData) override;
    virtual void Fini() override; /*IRole被从框架中摘除时，才调用IRole::Fini()*/

public:
    // public Player
    virtual int GetX() override;
    virtual int GetY() override;

public:
    GameProtocol *m_protocol = nullptr;

private:
    // 玩家在游戏里的坐标
    float x = 0;                                        //横
    float y = 0;                                        //高
    float z = 0;                                        //纵
    float v = 0;                                        //视角
    int iPid = 0;                                       //玩家ID
    std::string szName;                                 //玩家姓名
    GameMsg *CreateIDNameLogin();                       //向自己发送  自己的ID和Name 1
    GameMsg *CreateSurPlayers();                        //向自己发送  周围玩家       202
    GameMsg *CreateSelfPosition();                      //向周围玩家，发送自己的位置 200
    GameMsg *CreateIDNameLogoff();                      //向周围玩家，发送下线通知   201
    GameMsg *CreateTalkBroadCast(std::string _content); //向周围玩家，发送聊天广播   2
    /*
     *新位置：移动 3
     *玩家移动处理
     *1、视野切换(跨网格处理)
     *1.1、和新邻居互发200号消息，保证相互能看到彼此
     *1.2、和旧邻居互发201号消息，保证互相看到不彼此
     *2、广播新位置给周围玩家
     * */
    void ProcTalkMsg(std::string _content);                   //广播聊天消息
    void ProcMoveMsg(float _x, float _y, float _z, float _v); //发送新位置
    void ViewAppear(GameRole *_pRole);                        //视野出现
    void ViewLost(GameRole *_pRole);                          //视野消失
};
#endif