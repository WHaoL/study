#include "IChannel.h"
#include "ZinxKernel.h"
IChannel::IChannel()
{
}
IChannel::~IChannel()
{
}
//把待发送数据,存到缓存
//将参数记录到缓存，注册写检测到epoll树
void IChannel::Data_Sendout(std::string _output)
{
    //存入缓冲区
    m_buff.append(_output.begin(), _output.end());
    //修改epoll的监听类型：添加out方向的监听
    ZinxKernel::GetInstance().ModChannel_AddOut(this);
}
//把缓存中的数据,输出出去
void IChannel::flushout()
{
    WriteFd(m_buff);
    m_buff.clear();
}