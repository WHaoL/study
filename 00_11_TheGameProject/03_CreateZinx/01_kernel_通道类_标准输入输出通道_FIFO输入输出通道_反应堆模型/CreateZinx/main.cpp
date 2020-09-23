#include <iostream>
#include "ZinxKernel.h"
#include "StdinChannel.h"
#include "StdoutChannel.h"
#include "FIFOChannel.h"
int main()
{
    ZinxKernel &kernel = ZinxKernel::GetInstance();

    StdinChannel in_channel;
    StdoutChannel out_channel;
    in_channel.m_stdoutChannel = &out_channel;
    kernel.AddChannel(&in_channel);
    kernel.AddChannel(&out_channel);

    FIFOChannel fifo_input("myfifo_input", true); 
    FIFOChannel fifo_output("myfifo_output", false);
    fifo_input.m_fifo_out_channel = &fifo_output;
    kernel.AddChannel(&fifo_input); 
    kernel.AddChannel(&fifo_output);

    kernel.run();

    return 0;
}
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