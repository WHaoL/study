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
    //2.初始化本地的地址信息，主要是绑定端口：Port(接受广播数据)
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    addr.sin_addr.s_addr = INADDR_ANY; //自动绑定本地IP
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    //3.通信
    while (1)
    {
        char buf[1024];

        //4.1.接受广播数据
        recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        printf("服务器发来的数据是：%s\n", buf);
    }
    //4.关闭通信的fd
    close(fd);
    return 0;
}