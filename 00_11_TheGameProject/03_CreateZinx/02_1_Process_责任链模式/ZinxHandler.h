#ifndef __ZINXHANDLER_H__
#define __ZINXHANDLER_H__
class ZinxMsg
{
public:
    ZinxMsg() {}
    virtual ~ZinxMsg() {}
};

class ZinxHandler
{
public:
    ZinxHandler() {}
    virtual ~ZinxHandler() {}

public:
    /* 责任链的链子 */
    void handle(ZinxMsg *_msg_input);
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input) = 0;
    /* _msg_input_toNext是internel_handle()的返回值 */
    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext) = 0;
};

#endif