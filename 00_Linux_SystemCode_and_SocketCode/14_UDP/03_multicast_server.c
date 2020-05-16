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
    //2.设置组播属性
    struct in_addr myaddr;
    inet_pton(AF_INET,"192.168.184.132",&myaddr.s_addr);
    setsockopt(fd,IPPROTO_IP,IP_MULTICAST_IF,&myaddr,sizeof(myaddr));
    //3.初始化组播的地址信息：发送时使用(组播端口和组播地址)
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    inet_pton(AF_INET,"239.0.1.10",&addr.sin_addr.s_addr);
    
    //4.通信：组播发送数据
    int num = 0;
    while(1)
    {
        char buf[1024];
        sprintf(buf,"你好客户端...%d...",num++);
        sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&addr,sizeof(addr));
        sleep(1);
    }
    //5.关闭fd
    close(fd);
    
    return 0;
}

