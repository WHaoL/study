#ifndef __ROLES_H__
#define __ROLES_H__
#include <zinx.h>

// 回显类（全局唯一）
// 可以设计成：单例模式
class EchoRole : public Irole
{
public:
    EchoRole() {}
    virtual ~EchoRole() {}

public:
    virtual bool Init() override;
    virtual UserData *ProcMsg(UserData &_poUserData) override;
    virtual void Fini() override;
};

//输出控制类：控制输出通道打开/关闭
class OutputCtrlRole : public Irole
{
public:
    OutputCtrlRole() {}
    virtual ~OutputCtrlRole() {}

public:
    virtual bool Init() override;
    virtual UserData *ProcMsg(UserData &_poUserData) override;
    virtual void Fini() override;

private:
    // 记录上次摘除的输出通道，方便下次添加(添加成功后记得置为nullptr)
    Ichannel *poOut = nullptr;
};

//日期前缀类：控制是否添加日期前缀
class DatePreRole : public Irole
{
public:
    DatePreRole() {}
    virtual ~DatePreRole() {}

public:
    virtual bool Init() override;
    virtual UserData *ProcMsg(UserData &_poUserData) override;
    virtual void Fini() override; 

public:
    bool isNeedAddDate = false;
};

#endif