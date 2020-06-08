#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/un.h>

int main()
{
    // 1. 创建用于通信的套接字
    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }

    // 2. 绑定一个本地套接字
    struct sockaddr_un cliaddr;
    cliaddr.sun_family = AF_LOCAL;
    strcpy(cliaddr.sun_path, "client.sock");    // 客户端绑定的套接字文件
    bind(fd, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
    
    // 3. 连接服务器
    struct sockaddr_un addr;
    addr.sun_family = AF_LOCAL;
    strcpy(addr.sun_path, "server.sock");    // 服务器端绑定的套接字文件
    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("connect");
        exit(0);
    }


    int i = 0;
    // 通信
    while(1)
    {
        // 读数据
        char recvBuf[1024];
        // 写数据
        sprintf(recvBuf, "data: %d\n", i++);
        write(fd, recvBuf, strlen(recvBuf)+1);
        // 如果客户端没有发送数据, 默认阻塞
        read(fd, recvBuf, sizeof(recvBuf));
        printf("recv buf: %s\n", recvBuf);
        sleep(1);
    }

    // 释放资源
    close(fd); 

    return 0;
}
