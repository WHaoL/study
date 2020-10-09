#include "StdinChannel.h"
#include <iostream>
#include "StdoutChannel.h"

StdinChannel::StdinChannel() {}
StdinChannel::~StdinChannel() {}

//继承自IChannel
bool StdinChannel::Init() { return true; }
void StdinChannel::Fini() {}
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
    //将数据交给处理类(class Process;) 
    m_proc->DataProc(_input);
}