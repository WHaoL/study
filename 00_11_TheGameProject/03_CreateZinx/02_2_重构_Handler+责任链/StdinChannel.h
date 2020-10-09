#ifndef __STDINCHANNEL_H__
#define __STDINCHANNEL_H__
#include <string>
#include "IChannel.h"
#include "Process.h"

class StdinChannel : public IChannel
{
public:
    StdinChannel();
    virtual ~StdinChannel();
    Process *m_proc = nullptr; //把收到的数据，交给它处理

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