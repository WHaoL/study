#ifndef __ICHANNEL_H__
#define __ICHANNEL_H__
#include <string>

//应用了Reactor模式(反应堆)
class IChannel
{
public:
    IChannel();
    virtual ~IChannel();

public:
    virtual bool Init() = 0;
    virtual void Fini() = 0;
    virtual std::string ReadFd() = 0;
    virtual void WriteFd(std::string _output) = 0;
    virtual int GetFd() = 0;
    virtual void Data_Process(std::string _input) = 0;

    void Data_Sendout(std::string _output);
    void flushout();

private:
    std::string m_buff;
};
#endif