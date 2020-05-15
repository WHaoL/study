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
    //2.设置广播属性
    int opt = 1;//1代表设置广播属性，0代表不设置广播属性
    setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));
    //3.初始化广播的地址信息：发送数据时使用
    //3.1.对方接受广播数据的：Port
    //3.2.广播IP
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    inet_pton(AF_INET,"192.168.184.255",&addr.sin_addr.s_addr);
    //4.通信
    int num = 0;
    while(1)
    {
        char buf[1024];
        
        //4.1.发送数据
        sprintf(buf,"你好客户端...%d...",num++);
        sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&addr,sizeof(addr));
        sleep(1);
    }
    //关闭通信的fd
    close(fd);
    return 0;
}

