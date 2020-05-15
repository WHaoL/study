#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    //1.创建通信的套接字
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.初始化服务器的IP、Port
    struct sockaddr_in ser_addr;
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(9898);
    inet_pton(AF_INET,"192.168.184.132",&ser_addr.sin_addr.s_addr);
    
    //3.通信
    int num = 0;
    while(1)
    {
        //3.1.发送数据
        char buf[1024];
        sprintf(buf,"----你好服务器--%d...",num++);
        sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&ser_addr,sizeof(ser_addr));

        //3.2.接收数据
        recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
        printf("服务器发来数据：%s\n",buf);
        sleep(1);
    }
    //4.关闭通信的fd
    close(fd);
    return 0;
}

