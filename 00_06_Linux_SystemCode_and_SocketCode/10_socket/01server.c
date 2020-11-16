// 01server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    //1.创建监听的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定本地IP和端口
    struct sockaddr_in addr;
    addr.sin_port = htons(9000); //空闲端口即可
    inet_pton(AF_INET, "192.168.184.132", &addr.sin_addr.s_addr);
    addr.sin_family = AF_INET;
    int ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
        exit(0);
    }
    //3.设置监听
    ret = listen(fd, 128);
    if (ret == -1)
    {
        perror("listen");
        exit(0);
    }
    //4.阻塞等待客户端连接，并且接受建立连接
    struct sockaddr_in cliaddr;
    int len = sizeof(cliaddr);
    printf("等待客户端连接...\n");
    int cfd = accept(fd, (struct sockaddr *)&cliaddr, &len);
    if (cfd == -1)
    {
        perror("accept");
        exit(0);
    }

    char buf[24];
    printf("client IP：%s，port：%d\n",
           inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, buf, sizeof(buf)),
           ntohs(cliaddr.sin_port));

    //5.通信
    while (1)
    {
        //接受数据
        char buff[24];
        int len = read(cfd, buff, sizeof(buff));
        if (len > 0)
        {
            //接收到了对方的数据
            printf("recv buf：%s\n", buff);
        }
        else if (len == 0)
        {
            printf("client disconnect...\n");
            break;
        }
        else
        {
            perror("read");
            break;
        }

        //发送数据
        char *p = "你好，客户端...\n";
        write(cfd, p, strlen(p) + 1);
    }

    //6.关闭
    close(cfd);
    close(fd);
    return 0;
}