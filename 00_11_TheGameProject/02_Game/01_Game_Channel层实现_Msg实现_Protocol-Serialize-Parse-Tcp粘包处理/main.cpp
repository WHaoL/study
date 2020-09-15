#include <zinx.h>
#include <ZinxTCP.h>
#include "GameChannel.h"
#include "GameMsg.h"
#include "msg.pb.h"
#include <google/protobuf/message.h>

/*
 *Channel负责接收用户发送的字符串
 *Protocol负责把用户发送的字符串封装为用户请求
 *Role负责处理用户请求
 *Msg是我们封装的数据结构，在Protocol层和Role层之间进行传递
 * */
int main()
{
    pb::SyncPid *pmsg = new pb::SyncPid();
    pmsg->set_pid(1);
    pmsg->set_username("test");

    GameMsg gm(GameMsg::MSG_TYPE_LOGIN_IN_NAME, pmsg);
    auto output = gm.serialize();
    for (auto byte : output)
    {
        printf("%02X ", byte);
    }
    puts(" ");

    char buf[] = {0x08, 0x01, 0x12, 0x04, 0x74, 0x65, 0x73, 0x74};
    std::string input(buf, sizeof(buf));
    auto inputGame = GameMsg(GameMsg::MSG_TYPE_LOGIN_IN_NAME, input);
    std::cout << (dynamic_cast<pb::SyncPid *>(inputGame.pMsg))->pid() << std::endl;
    std::cout << (dynamic_cast<pb::SyncPid *>(inputGame.pMsg))->username() << std::endl;

    ZinxKernel::ZinxKernelInit();

    ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(8899, new GameConnFact())));

    ZinxKernel::Zinx_Run();

    ZinxKernel::ZinxKernelFini();
    return 0;
}