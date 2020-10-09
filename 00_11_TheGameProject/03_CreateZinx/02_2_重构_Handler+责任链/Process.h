#ifndef __PROCESS_H__
#define __PROCESS_H__
#include <string>
#include "IChannel.h"
#include "ZinxHandler.h"
class Process : public ZinxHandler
{
public:
    IChannel *m_out_channel = nullptr;
public:
    Process();
    virtual ~Process();
public:
    //继承自Ichannel
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input) override;
    /* _msg_input_toNext是internel_handle()的返回值 */
    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext) override;
};

#endif