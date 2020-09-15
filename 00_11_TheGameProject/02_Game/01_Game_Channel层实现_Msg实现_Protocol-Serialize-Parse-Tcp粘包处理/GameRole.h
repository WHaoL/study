#ifndef __GAMEROLE_H__
#define __GAMEROLE_H__
#include <zinx.h>
/*
 *决策类 
 */
class GameRole : public Irole
{
    virtual bool Init() override;
    virtual UserData *ProcMsg(UserData &_poUserData) override;
    virtual void Fini() override;
};
#endif