#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>

int main()
{
    //1.创建通信的套接字
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //3.初始化本地地址信息：主要是绑定Port(接受数据使用)
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    //3.加入到多播组
    struct ip_mreqn mymreqn;
    mymreqn.imr_address.s_addr = INADDR_ANY;//本地IP
    inet_pton(AF_INET,"239.0.1.10",&mymreqn.imr_multiaddr.s_addr);//组播地址
    mymreqn.imr_ifindex = if_nametoindex("ens33");//获取网卡信息
    setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mymreqn,sizeof(mymreqn));

    
    //4.通信：接收组播消息
    int num = 0;
    while(1)
    {
        char buf[1024];
        recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
        printf("服务器的数据：%s\n",buf);
        
    }
    //5.关闭fd
    close(fd);
    
    return 0;
}

