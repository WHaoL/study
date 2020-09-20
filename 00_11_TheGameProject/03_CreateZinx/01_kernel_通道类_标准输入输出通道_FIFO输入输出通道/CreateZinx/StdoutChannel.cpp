#include "StdoutChannel.h"
#include <iostream>
//继承自IChannel
bool StdoutChannel::Init() 
{
    //打开文件
}
void StdoutChannel::Fini() 
{
    //关闭文件
}
std::string StdoutChannel::ReadFd() { return std::string(); }
void StdoutChannel::WriteFd(std::string _output)
{
    std::cout << _output << std::endl;
}
int StdoutChannel::GetFd() { return 1; }
void StdoutChannel::Data_Process(std::string _input) {}