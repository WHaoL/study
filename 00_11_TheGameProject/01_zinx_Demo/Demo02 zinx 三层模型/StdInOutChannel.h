#ifndef __STDINOUTCHANNEL_H__
#define __STDINOUTCHANNEL_H__

#include <zinx.h>
#include <ZinxTCP.h>

/* 
 * 标准输入类
 */
class StdInChannel : public Ichannel
{
public:
    StdInChannel();
    virtual ~StdInChannel();

    virtual bool Init() override;
    virtual bool ReadFd(std::string &_input) override;
    virtual bool WriteFd(std::string &_output) override;
    virtual void Fini() override;
    virtual int GetFd() override;
    virtual std::string GetChannelInfo() override;
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;
};

/* 
 * 标准输出类
 */
class StdOutChannel : public Ichannel
{
public:
    StdOutChannel();
    virtual ~StdOutChannel();

    virtual bool Init() override;
    virtual bool ReadFd(std::string &_input) override;
    virtual bool WriteFd(std::string &_output) override;
    virtual void Fini() override;
    virtual int GetFd() override;
    virtual std::string GetChannelInfo() override;
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;
};

/* 
 * TCP数据通道类
 */
class myTcpData : public ZinxTcpData
{
public:
    myTcpData(int fd) : ZinxTcpData{fd} {}

public:
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;
};

/* 
 * TCP工厂类
 */
class myTcpFactory : public IZinxTcpConnFact
{
    virtual ZinxTcpData *CreateTcpDataChannel(int _fd) override;
};

#endif