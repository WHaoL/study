#include "ZinxHandler.h"

void ZinxHandler::handle(ZinxMsg *_msg_input)
{
    //1、当前环节处理
    ZinxMsg *p_msg = internel_handle(_msg_input);
    if (nullptr != p_msg)
    {
        //2、获取下一个环节(根据消息类型，决定不同的nextHandler)
        ZinxHandler *p_next_handler = GetNextHandler(p_msg);
        if (nullptr != p_next_handler)
        {
            //3、把数据传给下一个环节，下一个环节负责处理
            p_next_handler->handle(p_msg);
        }

        delete p_msg;
    }
}