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
    virtual void Fini() override;/*IRole被从框架中摘除时，才调用IRole::Fini()*/

public:
    // public Player
    virtual int GetX() override;
    virtual int GetY() override;

public:
    GameProtocol *m_protocol = nullptr;

private:
    // 玩家在游戏里的坐标
    float x = 0;                   //横
    float y = 0;                   //高
    float z = 0;                   //纵
    float v = 0;                   //视角
    int iPid = 0;                  //玩家ID
    std::string szName;            //玩家姓名
    GameMsg *CreateIDNameLogin();  //向自己发送 自己的ID和Name
    GameMsg *CreateSurPlayers();   //向自己发送 周围玩家
    GameMsg *CreateSelfPosition(); //向周围玩家，发送自己的位置
    GameMsg *CreateIDNameLogoff(); //向周围玩家，发送下线通知
};
#endif