#include "Roles.h"
#include <zinx.h>
#include "CommandMassage.h"
#include "CommandRecognition.h"
#include <iostream>
using namespace std;

//回显类
bool EchoRole::Init() { return true; }
UserData *EchoRole::ProcMsg(UserData &_poUserData)
{
    // 写出去
    GET_REF2DATA(CommandMassage, userdata, _poUserData);
    CommandMassage *pret = new CommandMassage(userdata);
    ZinxKernel::Zinx_SendOut(*pret, *(CommandRecognition::GetInstance()));
    // 注意：
    // 并不是调用Zinx_SendOut()时就直接把数据发送出去了，而是等到标准输出可以发送时，才进行发送
    // 当ProcMsg()函数返回之后，形参_poUserData对应的对象就会被析构掉了
    // 所以参数里的UserDATA不能使用直接传进来的引用对象，而应该new一个堆对象

    return nullptr;
}
void EchoRole::Fini() {}

//输出控制类：控制输出通道打开/关闭
bool OutputCtrlRole::Init()
{
    // 设置下一个处理环节是DatePreRole对象
    std::list<Irole *> &rolelist = ZinxKernel::Zinx_GetAllRole();
    Irole *ponext = nullptr;
    for (Irole *porole : rolelist)
    {
        DatePreRole *podateprerole = dynamic_cast<DatePreRole *>(porole);
        if (nullptr != podateprerole)
        {
            ponext = podateprerole;
            break;
        }
    }
    if (nullptr != ponext)
    {
        SetNextProcessor(*ponext);
    }
    return true;
}
UserData *OutputCtrlRole::ProcMsg(UserData &_poUserData)
{
    GET_REF2DATA(CommandMassage, userdata, _poUserData);
    if (true == userdata.isOpen)
    {
        // 打开输出通道
        // 只有摘除过一次才会被记录下来，没有被摘除过那么指针一直为nullptr
        if (nullptr != poOut)
        {
            ZinxKernel::Zinx_Add_Channel(*poOut);
            poOut = nullptr;
        }
    }
    else
    {
        // 关闭输出通道，从ZinxKernel中摘除输出通道
        Ichannel *poOutChannel = ZinxKernel::Zinx_GetChannel_ByInfo("stdout");
        ZinxKernel::Zinx_Del_Channel(*poOutChannel);

        // 把摘除的输出通道，记录到对象内
        // 当需要添加通道时，就会很方便
        poOut = poOutChannel;
    }
    return new CommandMassage(userdata);
}
void OutputCtrlRole::Fini() {}

//日期前缀类：控制是否添加日期前缀
bool DatePreRole::Init()
{
    // 设置下一个处理环节是EchoRole对象
    std::list<Irole *> &rolelist = ZinxKernel::Zinx_GetAllRole();
    Irole *ponext = nullptr;
    for (Irole *porole : rolelist)
    {
        EchoRole *poechorole = dynamic_cast<EchoRole *>(porole);
        if (nullptr != poechorole)
        {
            ponext = poechorole;
            break;
        }
    }
    if (nullptr != ponext)
    {
        SetNextProcessor(*ponext);
    }

    return true;
}
UserData *DatePreRole::ProcMsg(UserData &_poUserData)
{
    CommandMassage *poRet = nullptr;

    GET_REF2DATA(CommandMassage, userdata, _poUserData);

    // 如果消息是命令，则改变标志位
    if (userdata.isCmd)
    {
        isNeedAddDate = userdata.isRequireedDatePrefix;
    }
    else // 如果消息是需要回显的内容，则添加字符串，并交给回显功能对象
    {
        if (true == isNeedAddDate)
        {
            time_t tmp;
            time(&tmp);
            char *currentTime = ctime(&tmp);
            currentTime[strlen(currentTime) - 1] = '\0';

            poRet = new CommandMassage(userdata);
            poRet->szUserData = string(currentTime) + " " + poRet->szUserData;
        }
        else
        {
            poRet = new CommandMassage(userdata);
        }
    }

    return poRet;
}
void DatePreRole::Fini() {}