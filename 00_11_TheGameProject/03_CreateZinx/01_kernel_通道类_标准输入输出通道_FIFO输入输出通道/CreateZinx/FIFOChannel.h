#ifndef __FIFOCHANNEL_H__
#define __FIFOCHANNEL_H__
#include "IChannel.h"
#include <string>
class FIFOChannel : public IChannel
{
public:
    FIFOChannel(std::string _m_fifoName,bool _isRead);
    virtual ~FIFOChannel();

private:
    std::string m_fifo_name;
    int m_fifo_fd = -1;
    bool isRead = true;//打开FIFO是读 还是 写
public:
    FIFOChannel *m_fifo_out_channel = nullptr;

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