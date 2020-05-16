#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <assert.h>
int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        printf("参数个数过少\n");
        exit(0);
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    // 1.创建 fd
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    //assert(fd >= 0);
    if (fd == -1)
    {
        perror("socket");
        exit(0);
    }

    // 远端-server的ip和port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serverAddr.sin_addr.s_addr);
    serverAddr.sin_port = htons(port);

    //2.连接服务器
    int ret = connect(fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (-1 == ret)
    {
        perror("connect");
        close(fd);
        exit(0);
    }

    // 3.通信
    while (1)
    {
        char buf[1024] = {0};
        // fgets(buf, sizeof(buf), stdin); //从终端读取数据存入buf，发送给服务器
        // write(fd, buf, strlen(buf) + 1);

        //如果服务器没有发送数据，read默认阻塞
        if (read(fd, buf, sizeof(buf)) == 0)
        {
            printf("对方关闭了连接\n");
            break;
        }
        printf("server发送过来的数据是：%s\n", buf);
        sleep(1); //间隔1s进行数据的发送和接收
    }
    close(fd);
    return 0;
}