#include "Process.h"
#include <algorithm>
#include "IChannel.h"
using namespace std;
#include "ZinxHandler.h"
#include "ZinxKernel.h"

Process::Process(){}
Process::~Process() {}

ZinxMsg *Process::internel_handle(ZinxMsg *_msg_input)
{
    //参数中第一个字母是小写字母，则转大写
    //否则原样
    ByteMsg *byte = dynamic_cast<ByteMsg *>(_msg_input);
    if (nullptr != byte)
    {
        std::string nextString = byte->m_content;
        if (nextString[0] >= 'a' && nextString[0] <= 'z')
        {
            transform(nextString.begin(),
                      nextString.end(),
                      nextString.begin(),
                      ::toupper);
        }
        //产生ByteMsg类型的消息,交给下一级
        //根据原数据和新添加的数据，封装成一个新的数据，传给下一级
        // byte->m_dir = System_IO_Direction_Msg::IO_OUT;
        // return new ByteMsg(*byte, nextString);

        //调用发送函数
        ZinxKernel::GetInstance().Zinx_sendout(nextString,m_out_channel);
    }
    return nullptr;
}
/* _msg_input_toNext是internel_handle()的返回值 */
ZinxHandler *Process::GetNextHandler(ZinxMsg *_msg_input_toNext)
{
    // return m_out_channel;
    return nullptr;
}