#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/un.h>

int main()
{
    // 1. 创建用于监听的套接字
    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }

    // 2. 绑定本地
    struct sockaddr_un addr;
    addr.sun_family = AF_LOCAL;
    strcpy(addr.sun_path, "server.sock");
    // 绑定成功server.sock文件被创建
    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("bind");
        exit(0);
    }

    // 3.设置监听
    ret = listen(fd, 100);
    if(ret == -1)
    {
        perror("listen");
        exit(0);
    }

    // 4. 等待, 接受连接请求
    struct sockaddr_un addrCli;//存储客户端的addr
    int len = sizeof(addrCli);
    printf("正在焦急等待客户端的连接...\n");
    int connfd = accept(fd, (struct sockaddr*)&addrCli, &len);
    if(connfd == -1)
    {
        perror("accept");
        exit(0);
    }
    // 得到客户端进程绑定的本地套接字文件的名字
    printf("client socket fileName: %s\n", addrCli.sun_path);

    int num = 0;
    // 通信
    while(1)
    {
        // 读数据
        char recvBuf[1024];
        // 如果客户端没有发送数据, 默认阻塞
        int ret = read(connfd, recvBuf, sizeof(recvBuf));
        if(ret == -1)
        {
            perror("read");
            break;
        }
        else if(ret == 0)
        {
            printf("客户端已经断开了连接...\n");
            break;
        }
        else
        {
            printf("recv buf: %s\n", recvBuf);
            // 写数据
            write(connfd, recvBuf, strlen(recvBuf));
        }
    }
	
	
    // 释放资源
	close(connfd);  // 通信
    close(fd);  // 监听
    return 0;
}