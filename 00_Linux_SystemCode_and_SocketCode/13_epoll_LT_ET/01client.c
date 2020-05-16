#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>


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
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    inet_pton(AF_INET,"192.168.184.132",&addr.sin_addr.s_addr);
    int ret = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret == -1)
    {
        perror("accept");
        exit(0);
    }
    //通信
    while(1)
    {
        char recvbuf[1024];
        //从终端读取数据存入recvbuf，发送给服务器
        fgets(recvbuf,sizeof(recvbuf),stdin);
        write(fd,recvbuf,strlen(recvbuf)+1);

        //如果服务器没有发送数据，read默认阻塞
        read(fd,recvbuf,sizeof(recvbuf));
        printf("客户端输入的数据是：%s\n",recvbuf);
        sleep(1);//间隔1s进行数据的发送和接收
    }
    //释放资源
    close(fd);
    return 0;
}

