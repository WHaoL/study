#include "StdinChannel.h"
#include <iostream>
#include "StdoutChannel.h"

StdinChannel::StdinChannel() {}
StdinChannel::~StdinChannel() {}
//继承自IChannel
bool StdinChannel::Init() 
{
    //打开文件
    return true;
}
void StdinChannel::Fini() 
{
    //关闭文件
}
std::string StdinChannel::ReadFd()
{
    std::string ret;
    std::cin >> ret;
    return ret;
}
void StdinChannel::WriteFd(std::string _output) {}
int StdinChannel::GetFd() { return 0; }
void StdinChannel::Data_Process(std::string _input)
{
    //将数据回显到标准输出，调用标准输出通道对象的sendout()
    m_stdoutChannel->Data_Sendout(_input);
}