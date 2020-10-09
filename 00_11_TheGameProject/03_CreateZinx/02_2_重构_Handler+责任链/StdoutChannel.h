#ifndef __STDOUTCHANNEL_H__
#define __STDOUTCHANNEL_H__
#include "IChannel.h"
class StdoutChannel : public IChannel
{
public:
    StdoutChannel() {}
    virtual ~StdoutChannel() {}

public:
    //继承自IChannel
    bool Init() override;
    void Fini() override;
    std::string ReadFd() override;
    void WriteFd(std::string _output) override;
    int GetFd() override;
    
    virtual ZinxHandler *GetInputNextStage(ByteMsg *_byte) override; 
};
#endif