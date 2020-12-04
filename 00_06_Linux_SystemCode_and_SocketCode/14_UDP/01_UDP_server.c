#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    //1.创建通信的套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定本地IP、Port
    struct sockaddr_in addr;
    addr.sin_port = htons(9898);
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_family = AF_INET;
    int ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
        exit(0);
    }
    //3.通信
    while (1)
    {
        //3.1.接受数据
        char buf[1024];
        struct sockaddr_in cliaddr;
        int lencli = sizeof(cliaddr);
        recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, &lencli);

        //对方的IP
        char ip[17];
        inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, sizeof(ip));
        //对方的Port
        unsigned short int port = ntohs(cliaddr.sin_port);
        printf("客户端发来的:%s,IP:%s,Port:%d\n", buf, ip, port);

        //3.2.发送数据
        sprintf(buf, "客户端的IP:%s,Port:%d", ip, port);
        sendto(fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }
    //4.关闭通信的fd
    close(fd);
    return 0;
}