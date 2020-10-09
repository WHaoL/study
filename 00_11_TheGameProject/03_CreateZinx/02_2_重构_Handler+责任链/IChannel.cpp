#include "IChannel.h"
#include "ZinxKernel.h"
IChannel::IChannel()
{
}
IChannel::~IChannel()
{
}
//1、把待发送数据,存到缓存，2、对this，epoll树上检测input改为检测input|output
void IChannel::Data_Sendout(std::string _output)
{
    m_buff.append(_output.begin(), _output.end());     //存入缓冲区
    ZinxKernel::GetInstance().ModChannel_AddOut(this); //修改epoll的监听类型：添加out方向的监听
}

//把缓存中的数据,输出出去
void IChannel::flushout()
{
    WriteFd(m_buff);
    m_buff.clear();
}

ZinxMsg *IChannel::internel_handle(ZinxMsg *_msg_input)
{
    //判断消息的方向是in还是out
    System_IO_Direction_Msg *pmsg = dynamic_cast<System_IO_Direction_Msg *>(_msg_input);
    if (nullptr != pmsg)
    {
        if (System_IO_Direction_Msg::IO_IN == pmsg->m_dir)
        {
            std::string inputdata = ReadFd();
            return new ByteMsg(*pmsg, inputdata);
        }
        else if (System_IO_Direction_Msg::IO_OUT == pmsg->m_dir)
        {
            //消息来自业务层
            //把数据存到缓存，并修改epoll的监听类型
            ByteMsg *pout = dynamic_cast<ByteMsg *>(_msg_input);
            if (nullptr != pout)
                Data_Sendout(pout->m_content);
        }
    }
    return nullptr;
}

//抽象类不知道下一个处理环节是谁，所以应该由子类去确定
ZinxHandler *IChannel::GetNextHandler(ZinxMsg *_msg_input_toNext)
{
    ByteMsg *pbyte = dynamic_cast<ByteMsg *>(_msg_input_toNext);
    if (nullptr != pbyte)
    {
        return GetInputNextStage(pbyte);
    }
    return nullptr;
}