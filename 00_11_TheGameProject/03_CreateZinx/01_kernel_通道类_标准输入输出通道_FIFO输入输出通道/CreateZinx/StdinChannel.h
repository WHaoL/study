#ifndef __STDINCHANNEL_H__
#define __STDINCHANNEL_H__
#include <string>
#include "IChannel.h"
#include "StdoutChannel.h"
class StdinChannel : public IChannel
{
public:
    StdinChannel();
    virtual ~StdinChannel();
    StdoutChannel *m_stdoutChannel = nullptr;

public:
    //继承自IChannel
    bool Init() override;
    void Fini() override;
    std::string ReadFd() override;
    void WriteFd(std::string _output) override;
    int GetFd() override;
    void Data_Process(std::string _input) override;
};
#endif