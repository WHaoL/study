#include <zinx.h>
#include <ZinxTCP.h>
#include "GameChannel.h"
#include "GameMsg.h"
#include "msg.pb.h"
//#include <google/protobuf/message.h>
#include "AOIWorld.h"
using namespace std;
#include "ZinxTimer.h"
#include "RandomName.h"
extern RandomName random_name; //在GameRole.cpp中创建该对象

/*把当前进程设置为守护进程 && 进程监控*/
void Daemon_ProcessMonitor();

/*测试*/
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
    Daemon_ProcessMonitor(); /*把当前进程设置为守护进程 && 进程监控*/

    random_name.LoadFile(); //生成名字池

    ZinxKernel::ZinxKernelInit();
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(8899, new GameConnFact())));
    ZinxKernel::Zinx_Add_Channel(*(new ZinxTimerChannel()));
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();
    return 0;
}

/*把当前进程设置为守护进程 && 进程监控*/
void Daemon_ProcessMonitor()
{
    /*把当前进程设置为守护进程*/
    // 1、fork
    pid_t pid = fork();
    if (pid < 0) //出错
    {
        perror(" fork() Error ");
        exit(-1);
    }

    // 2、父进程退出
    if (pid > 0)
    {
        exit(0);
    }

    // 3、子进程
    // 3.1设置回话ID
    setsid();
    // 3.2子进程设置执行路径(由于我们要读取路径下的txt文件，所以就不改路径了)
    // 3.3子进程从定向3个文件描述符到/dev/null
    int null_Fd = open("/dev/null", O_RDWR);
    if (null_Fd >= 0)
    {
        dup2(null_Fd, 0);
        dup2(null_Fd, 1);
        dup2(null_Fd, 2);
    }

    /*进程监控*/
    //服务端：如果服务端游戏进程异常退出，通过进程监控可以及时重新启动游戏进程
    //比如访问了野指针
    while (1)
    {
        // 1、fork
        pid_t pid_f = fork();
        if (pid_f < 0) //出错
        {
            perror(" fork() Error ");
            exit(-1);
        }

        if (pid_f > 0) // 2、父进程等子进程退出，子进程非正常退出，都能被拉起来
        {
            int iStatus = -1;
            wait(&iStatus);
            if (0 == iStatus)//表名子进程是正常退出，此时不重新启动服务，正常退出程序
            {
                exit(0);
            }
        }
        else //3、子进程跳出循环执行游戏业务
        {
            break;
        }
    }
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