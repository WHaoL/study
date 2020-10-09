#include "StdoutChannel.h"
#include <iostream>
//继承自IChannel
bool StdoutChannel::Init() { return true; }
void StdoutChannel::Fini() {}
std::string StdoutChannel::ReadFd() { return std::string(); }
void StdoutChannel::WriteFd(std::string _output)
{
    std::cout << _output << std::endl;
}
int StdoutChannel::GetFd() { return 1; }
ZinxHandler *StdoutChannel::GetInputNextStage(ByteMsg *_byte)
{
    return nullptr;
}