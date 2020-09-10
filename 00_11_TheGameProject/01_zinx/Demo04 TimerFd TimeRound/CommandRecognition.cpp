#include "CommandRecognition.h"
#include <zinx.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include "CommandMassage.h"
#include "Roles.h"

// 协议层

//单例
CommandRecognition *CommandRecognition::poSingle = new CommandRecognition{};

// 原始数据(字符串)，转换为 用户数据
UserData *CommandRecognition::raw2request(std::string _szInput)
{
    //先判断传进来的字符串——szInput是不是"exit",是的话，退出程序
    if ("exit" == _szInput)
    {
        ZinxKernel::Zinx_Exit();
        return nullptr;
    }

    //原始数据字符串赋值到用户数据中字符串字段
    CommandMassage *pret = new CommandMassage{};
    pret->szUserData = _szInput;

    // 判断是否是命令
    if ("open" == _szInput)
    {
        pret->isCmd = true;
        pret->isOpen = true;
    }
    if ("close" == _szInput)
    {
        pret->isCmd = true;
        pret->isOpen = false;
    }
    if ("date" == _szInput)
    {
        pret->isCmd = true;
        pret->isRequireedDatePrefix = true;
    }
    if ("cleardate" == _szInput)
    {
        pret->isCmd = true;
        pret->isRequireedDatePrefix = false;
    }
    return pret;
}
// 用户数据 转为原始数据(字符串)
std::string *CommandRecognition::response2raw(UserData &_oUserData)
{
    GET_REF2DATA(CommandMassage, Output, _oUserData);
    return new string(Output.szUserData);
}

// 消息的处理者
// 数据流向本机业务层
Irole *CommandRecognition::GetMsgProcessor(UserDataMsg &_oUserDataMsg)
{
    // 记录下每次的数据来源(来自哪个通道)
    szOutChannel = _oUserDataMsg.szInfo;
    if ("stdin" == szOutChannel)
    {
        szOutChannel = "stdout";
    }

    // 返回数据的处理者
    //根据命令不同，交给不同的role对象去处理

    // 判断消息是不是一条命令
    CommandMassage *pocmdmsg = dynamic_cast<CommandMassage *>(_oUserDataMsg.poUserData);
    bool isCmd = pocmdmsg->isCmd;

    //获取到所有的role对象
    //目前有EchoRole、OutputCtrlRole、
    std::list<Irole *> &rolelist = ZinxKernel::Zinx_GetAllRole();

    Irole *poreturnrole = nullptr;

    for (Irole *porole : rolelist)
    {
        if (isCmd)
        {
            // 动态类型转换，要么成功，要么失败(返回值为nullptr)
            OutputCtrlRole *pooutputctrlrole = dynamic_cast<OutputCtrlRole *>(porole);
            if (nullptr != pooutputctrlrole)
            {
                poreturnrole = pooutputctrlrole;
                break;
            }
        }
        else
        {
            DatePreRole *podateprerole = dynamic_cast<DatePreRole *>(porole);
            if (nullptr != podateprerole)
            {
                poreturnrole = podateprerole;
                break;
            }
        }
    }
    return poreturnrole;
}

// 数据流向输出层
Ichannel *CommandRecognition::GetMsgSender(BytesMsg &_oBytes)
{
    // 返回数据的发出者

    // 指定数据要通过标准输出输出
    // return ZinxKernel::Zinx_GetChannel_ByInfo("stdout");

    // szOutChannel记录下了每次的数据来源(来自哪个通道)
    return ZinxKernel::Zinx_GetChannel_ByInfo(szOutChannel);
}