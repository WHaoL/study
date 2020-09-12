#ifndef __COMMANDMASSAGE_H__
#define __COMMANDMASSAGE_H__

#include <zinx.h>
#include <string>

// 原始数据(传递给业务层使用)
class CommandMassage : public UserData
{
public:
    CommandMassage() {}
    virtual ~CommandMassage() {}

public:
    //成员变量表示：要回显的字符串
    std::string szUserData;

    //标志：开启/关闭输出，默认开启
    bool isOpen = true;

    //标志：本次消息是否是命令
    bool isCmd = false;

    //标志：是否添加日期前缀
    bool isRequireedDatePrefix = false;
};

#endif