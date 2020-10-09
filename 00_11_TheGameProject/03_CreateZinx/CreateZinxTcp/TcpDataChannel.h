#ifndef __TcpDataChannel_h__
#define __TcpDataChannel_h__
#include "zinx.h"

/*******************************************TcpDataChannel*******************************************/
/*数据通道*/
class TcpDataChannel : public Ichannel
{
private: /* data */
    int m_socketFd = -1;
public:
    TcpDataChannel(int _socketFd);
    virtual ~TcpDataChannel();

public:
    // 继承自Ichannel
    virtual bool Init() override;
    virtual bool ReadFd(std::string &_input) override;
    virtual bool WriteFd(std::string &_output) override;
    virtual void Fini() override;
    virtual int GetFd() override;
    virtual std::string GetChannelInfo() override;
    //virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;
};

/*******************************************TcpDataChannelFactory*******************************************/
/*工厂类：负责创建数据通道对象*/
class TcpDataChannelFactory
{
public:
    virtual TcpDataChannel *CreateChannel(int _fd) = 0;
};

/*******************************************TcpListenChannel*******************************************/
/*监听通道：调用工厂类产生数据通道对象*/
class TcpListenChannel : public Ichannel
{
private:
    /* data */
    TcpDataChannelFactory *m_factory = nullptr;
    unsigned short m_port = 0;
    int m_listenFd = -1;

public:
    TcpListenChannel(unsigned short _port, TcpDataChannelFactory *_pfact);
    virtual ~TcpListenChannel();

public:
    // 继承自Ichannel
    virtual bool Init() override;
    virtual bool ReadFd(std::string &_input) override;
    virtual bool WriteFd(std::string &_output) override;
    virtual void Fini() override;
    virtual int GetFd() override;
    virtual std::string GetChannelInfo() override;
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;
};

#endif