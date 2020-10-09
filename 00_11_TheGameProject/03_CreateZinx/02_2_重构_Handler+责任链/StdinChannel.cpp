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
ZinxHandler * StdinChannel::GetInputNextStage(ByteMsg *_byte)
{
    return m_proc;
}