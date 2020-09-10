#ifndef __COMMANDRECOGNITION_H__
#define __COMMANDRECOGNITION_H__
#include <zinx.h>

// 协议层
// 协议对象一个就行，设计成单例模式(全局唯一协议对象)
// 在整个程序运行之前就已经创建好该对象了
class CommandRecognition : public Iprotocol
{
private:
    CommandRecognition() {}
    virtual ~CommandRecognition() {}
    // 变量声明
    // 在.cpp文件中进行定义
    static CommandRecognition * poSingle;
    //标志数据的来源,然后从这个通道把数据发出去
    //收数据的时候进行赋值 GetMsgProcessor()
    // GetMsgProcessor()阶段的UserDataMsg就已经不是纯用户数据了，它已经包含了数据来源等信息
    std::string szOutChannel;

public:
    static CommandRecognition * GetInstance()
    {
        // 懒汉模式
        return poSingle;
    }

public:
    /*原始数据和业务数据交互函数，开发者重写该函数，实现协议*/
    virtual UserData *raw2request(std::string _szInput) override;

    /*原始数据和业务数据交互函数，开发者重写该函数，实现协议*/
    virtual std::string *response2raw(UserData &_oUserData) override;

    /*获取处理角色对象函数，开发者应该重写该函数，用来指定当前产生的用户数据消息应该传递给哪个角色处理*/
    virtual Irole *GetMsgProcessor(UserDataMsg &_oUserDataMsg) override;

    /*获取发送通道函数，开发者应该重写该函数，用来指定当前字节流应该由哪个通道对象发出*/
    virtual Ichannel *GetMsgSender(BytesMsg &_oBytes) override;
};

#endif