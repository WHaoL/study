// 03client.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    //1.创建通信的套接字
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.连接服务器
    struct sockaddr_in serverAddr;//服务器的相关数据
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(9898);
    inet_pton(AF_INET,"192.168.184.132",&serverAddr.sin_addr.s_addr);
    int ret = connect(fd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
    if(ret == -1)
    {
        perror("connect");
        exit(0);
    }
    //3.通信
    while(1)
    {
        //3.1.发送数据
        char *p = "你好服务器...";
        write(fd,p,strlen(p)+1);
        //3.2.接受数据
        char buf[1024];
        int len = read(fd,buf,sizeof(buf));
        if(len > 0)
        {
            printf("recv data:%s\n",buf);
        }
        else if(len == 0)
        {
            printf("server disconnect...\n");
            break;
        }
        else 
        {
            perror("read");
            exit(0);
        }
        sleep(1);
    }
    close(fd);
    return 0;
}

