#include "StdInOutChannel.h"
#include <zinx.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include "CommandRecognition.h"

/*
 * 标准输入类
 */
StdInChannel::StdInChannel() {}
StdInChannel::~StdInChannel() {}
bool StdInChannel::Init() { return true; }
bool StdInChannel::ReadFd(std::string &_input)
{
    cin >> _input;
    return true;
}
bool StdInChannel::WriteFd(std::string &_output) { return false; }
void StdInChannel::Fini() {}
int StdInChannel::GetFd() { return 0; }
std::string StdInChannel::GetChannelInfo() { return "stdin"; }
AZinxHandler *StdInChannel::GetInputNextStage(BytesMsg &_oInput)
{
    // 交给协议类去处理
    // 所以下一个处理者是：CommandRecognition类的对象
    return CommandRecognition::GetInstance();
}

/* 
 * 标准输出类
 */
StdOutChannel::StdOutChannel() {}
StdOutChannel::~StdOutChannel() {}
bool StdOutChannel::Init() { return true; }
bool StdOutChannel::ReadFd(std::string &_input) { return false; }
bool StdOutChannel::WriteFd(std::string &_output)
{
    cout << _output << endl;
    return true;
}
void StdOutChannel::Fini() {}
int StdOutChannel::GetFd() { return 1; }
std::string StdOutChannel::GetChannelInfo() { return "stdout"; }
AZinxHandler *StdOutChannel::GetInputNextStage(BytesMsg &_oInput)
{
    return nullptr;
}

/* 
 * TCP数据通道类
 */
AZinxHandler *myTcpData::GetInputNextStage(BytesMsg &_oInput)
{
    // 交给协议类去处理
    // 所以下一个处理者是：CommandRecognition类的对象
    return CommandRecognition::GetInstance();
}

/* 
 * TCP工厂类
 */
ZinxTcpData *myTcpFactory::CreateTcpDataChannel(int _fd) 
{
    return new myTcpData(_fd);
}
