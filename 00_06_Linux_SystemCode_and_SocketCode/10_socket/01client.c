// 01client.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    //1.创建通信的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.连接服务器
    struct sockaddr_in addr;
    addr.sin_port = htons(9000); //空闲端口即可
    inet_pton(AF_INET, "192.168.184.132", &addr.sin_addr.s_addr);
    addr.sin_family = AF_INET;
    int ret = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("connect");
        exit(0);
    }

    //3.通信
    while (1)
    {

        //发送数据
        char *p = "你好，服务器...\n";
        write(fd, p, strlen(p) + 1);

        //接受数据
        char buff[24];
        int len = read(fd, buff, sizeof(buff));
        if (len > 0)
        {
            //接收到了对方的数据
            printf("recv buf：%s\n", buff);
            sleep(1);
        }
        else if (len == 0)
        {
            printf("server disconnect...\n");
            break;
        }
        else
        {
            perror("read");
            break;
        }
    }

    //6.关闭
    close(fd);
    return 0;
}
