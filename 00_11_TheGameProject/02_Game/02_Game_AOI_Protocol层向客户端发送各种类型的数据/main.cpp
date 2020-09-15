#include <zinx.h>
#include <ZinxTCP.h>
#include "GameChannel.h"
#include "GameMsg.h"
#include "msg.pb.h"
//#include <google/protobuf/message.h>
#include "AOIWorld.h"
using namespace std;

void testProtobuf(); // 测试GameProtocol中的Protobuf
class myPlayer;
void testAOIWorld(); // 测试 AOIWorld


/*
 *Channel负责接收用户发送的字符串
 *Protocol负责把用户发送的字符串封装为用户请求
 *Role负责处理用户请求
 *Msg是我们封装的数据结构，在Protocol层和Role层之间进行传递
 * */
// client.exe 192.168.184.133 8899
int main()
{
    //testProtobuf();
    //testAOIWorld();

    ZinxKernel::ZinxKernelInit();
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(8899, new GameConnFact())));
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();
    return 0;
}

// 测试GameProtocol中的Protobuf
void testProtobuf()
{
    //测试：protobuf
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
    //测试：protobuf
    char buf[] = {0x08, 0x01, 0x12, 0x04, 0x74, 0x65, 0x73, 0x74};
    std::string input(buf, sizeof(buf));
    auto inputGame = GameMsg(GameMsg::MSG_TYPE_LOGIN_IN_NAME, input);
    std::cout << (dynamic_cast<pb::SyncPid *>(inputGame.pMsg))->pid() << std::endl;
    std::cout << (dynamic_cast<pb::SyncPid *>(inputGame.pMsg))->username() << std::endl;
}

class myPlayer : public Player
{
private:
    int x;
    int y;
    std::string name;

public:
    myPlayer(int _x, int _y, std::string _name) : x(_x), y(_y), name(_name) {}

    virtual int GetX() override { return x; }
    virtual int GetY() override { return y; }
    std::string GetName() { return name; }
};
// 测试 AOIWorld
void testAOIWorld()
{
    AOIWorld w(20, 200, 50, 230, 6, 6);
    myPlayer p1(60, 107, "玩家1");
    myPlayer p2(91, 118, "玩家2");
    myPlayer p3(147, 133, "玩家3");
    w.AddPlayer(&p1);
    w.AddPlayer(dynamic_cast<Player *>(&p2));
    w.AddPlayer(&p3);

    std::list<Player *> srd_list = w.GetSurrendPlayers(&p1);
    for (Player *&single : srd_list)
    {
        std::cout << dynamic_cast<myPlayer *>(single)->GetName()
                  << std::endl;
    }
}