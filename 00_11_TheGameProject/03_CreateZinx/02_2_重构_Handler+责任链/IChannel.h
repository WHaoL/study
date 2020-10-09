#ifndef __ICHANNEL_H__
#define __ICHANNEL_H__
#include <string>
#include "ZinxHandler.h"

//IO通道的方向
//epoll传递给通道层的数据类型
class System_IO_Direction_Msg : public ZinxMsg
{
public:
    enum IO_DIR // IO方向
    {
        IO_IN,
        IO_OUT
    } m_dir;

public:
    System_IO_Direction_Msg(IO_DIR _dir) : m_dir(_dir) {}
};

//IO通道的方向+数据内容
// 通道层和协议层之间传递的数据类型
class ByteMsg : public System_IO_Direction_Msg
{
public:
    std::string m_content; // 一堆字节
public:
    //传引用：用传入的IO方向，构造我的父类的IO方向
    ByteMsg(System_IO_Direction_Msg &_iodir,
            std::string _content) : System_IO_Direction_Msg(_iodir),
                                    m_content(_content) {}
};

//应用了Reactor模式(反应堆模型)
class IChannel : public ZinxHandler
{
public:
    IChannel();
    virtual ~IChannel();

public:
    virtual bool Init() = 0;
    virtual void Fini() = 0;
    virtual std::string ReadFd() = 0;
    virtual void WriteFd(std::string _output) = 0;
    virtual int GetFd() = 0;
    //virtual void Data_Process(std::string _input) = 0;

    void Data_Sendout(std::string _output);
    void flushout();

public:
    //通过ZinxHandler继承
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input) override;
    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext) override;

    virtual ZinxHandler *GetInputNextStage(ByteMsg *_byte) = 0; //子类负责确定nextHandler

private:
    std::string m_buff;
};
#endif