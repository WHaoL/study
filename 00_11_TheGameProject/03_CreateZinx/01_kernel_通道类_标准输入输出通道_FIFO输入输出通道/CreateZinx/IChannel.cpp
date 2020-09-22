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