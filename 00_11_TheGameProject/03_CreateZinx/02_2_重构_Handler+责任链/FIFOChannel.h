#ifndef __FIFOCHANNEL_H__
#define __FIFOCHANNEL_H__
#include "IChannel.h"
#include <string>
class FIFOChannel : public IChannel
{
public:
    FIFOChannel(std::string _m_fifoName, bool _isRead);
    virtual ~FIFOChannel();

private:
    std::string m_fifo_name; //FIFO文件的name
    bool isRead = true;      //以什么模式打开FIFO文件，是读 还是 写
    int m_fifo_fd = -1;      //得到FIFO文件的fd

public:
    FIFOChannel *m_fifo_out_channel = nullptr; //FIFO输出通道

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