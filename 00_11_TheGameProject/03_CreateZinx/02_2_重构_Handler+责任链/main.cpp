#include <iostream>
#include "ZinxKernel.h"
#include "StdinChannel.h"
#include "StdoutChannel.h"
#include "FIFOChannel.h"
#include "Process.h"
#include "ZinxHandler.h"
#include <algorithm>
//void test_Chain();


int main()
{
    //test_Chain();
    
    ZinxKernel &kernel = ZinxKernel::GetInstance();

    StdinChannel in_channel;              //输入
    Process my_proc;                      //处理
    StdoutChannel out_channel;            //输出
    in_channel.m_proc = &my_proc;         //输入交给处理
    my_proc.m_out_channel = &out_channel; //处理交给输出
    kernel.AddChannel(&in_channel);
    kernel.AddChannel(&out_channel);

    // FIFOChannel fifo_input("myfifo_input", true);
    // FIFOChannel fifo_output("myfifo_output", false);
    // fifo_input.m_fifo_out_channel = &fifo_output;
    // kernel.AddChannel(&fifo_input);
    // kernel.AddChannel(&fifo_output);

    kernel.run();

    return 0;
}
//-------------------------------------------------------------------------------//
class testMsg : public ZinxMsg
{
public:
    std::string data;
};
//责任链：环节3 下一个字母
class output_nextLetter : public ZinxHandler
{
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input)
    {
        testMsg *pmsg = dynamic_cast<testMsg *>(_msg_input);
        printf("%c\n", pmsg->data[0] + 1);
        return nullptr;
    }

    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext)
    {
        return nullptr;
    }
} step3; //定义全局对象

//责任链：环节2 转为ASIC码
class output_ASIC : public ZinxHandler
{
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input)
    {
        testMsg *pmsg = dynamic_cast<testMsg *>(_msg_input);
        printf("%d\n", pmsg->data[0]);

        //把输入的数据，原样交给下一个环节
        testMsg *pret = new testMsg();
        pret->data = pmsg->data;
        return pret;
    }

    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext)
    {
        return &step3;
    }
} step2; //定义全局对象
//责任链：环节1 转为大写字母
class tranceUpper : public ZinxHandler
{
    virtual ZinxMsg *internel_handle(ZinxMsg *_msg_input)
    {
        testMsg *pmsg = dynamic_cast<testMsg *>(_msg_input);
        std::string output(" ");
        std::transform(pmsg->data.begin(), pmsg->data.end(), output.begin(), ::toupper);
        std::cout << output << std::endl;

        //new新的消息对象 返回
        testMsg *pret = new testMsg();
        pret->data = output;
        return pret;
    }

    virtual ZinxHandler *GetNextHandler(ZinxMsg *_msg_input_toNext)
    {
        return &step2;
    }
} step1; //定义全局对象
/* 测试责任链 */
void test_Chain()
{
    std::string str;
    std::cin >> str;
    testMsg init_msg;
    init_msg.data = str;
    step1.handle(&init_msg);
}
//-------------------------------------------------------------------------------//
/*
 *测试fifo
 *
 *[root@lwh CreateZinx]# mkfifo myfifo_input 
 *[root@lwh CreateZinx]# mkfifo myfifo_output
 *
 *FIFO非阻塞打开时，测试步骤：先打开fifo的输出，再启动可执行程序
 *(因为非阻塞情况下，必须先打开fifo的输出端myfifo_output，然后再./execute时才可以打开fifo的输入端myfifo_input)
 *
 * 在第一个终端启动 ./execute
 * 在第二个终端，把数据输入到fifo_input  
 *      [root@lwh CreateZinx]# echo abc > myfifo_input
 * 在第三个终端，查看fifo_output的输出情况
 *      [root@lwh CreateZinx]# cat myfifo_output 
 * */
//-------------------------------------------------------------------------------//