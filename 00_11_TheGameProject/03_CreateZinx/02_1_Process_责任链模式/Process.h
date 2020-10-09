#ifndef __PROCESS_H__
#define __PROCESS_H__
#include <string>
#include "IChannel.h"
class Process
{
public:
    IChannel *m_out_channel = nullptr;

public:
    Process(/* args */);
    virtual ~Process();

public:
    void DataProc(std::string _input);
    void UpperOut(std::string _input);
    void OriginalOut(std::string _input);
};

#endif