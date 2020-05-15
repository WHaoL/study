// 02select_server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <arpa/inet.h>

int main()
{
    //1.创建监听的套接字
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定
    struct sockaddr_in addr;//本地IP、端口
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    //3.设置监听
    listen(fd,128);
    //4.要检测的读集合
    fd_set bkset,readset;
    FD_ZERO(&bkset);//清空集合
    FD_SET(fd,&bkset);//把监听的fd设置到集合中去
    //更新检测的集合的有效范围
    int maxfd = fd;
    while(1)
    {
        //6.1.委托内核检测某些fd的缓冲区，select默认阻塞
        readset = bkset;//给要检测的集合赋值
        int ret = select(maxfd+1,&readset,NULL,NULL,NULL);
        //6.2.判断是不是有客户端连接
        if(FD_ISSET(fd,&readset))
        {
            //接受连接请求
            struct sockaddr_in cliaddr;//存储客户端IP 端口
            int lencli = sizeof(cliaddr);
            int cfd = accept(fd,(struct sockaddr*)&cliaddr,&lencli);
            //得到通信的cfd，这个cfd也是需要内核检测的
            //把cfd添加到要检测的读集合中(添加到完整的集合中)
            FD_SET(cfd,&bkset);
            maxfd = maxfd > cfd?maxfd:cfd;//更新集合的有效范围
        }
        //6.3.判断是不是有客户端通信
        for(int i=fd+1;i<maxfd+1;++i)
        {
            if(FD_ISSET(i,&readset))
            {
                //接收数据，此时read/recv不阻塞，直接就可以读数据
                char buf[1024];
                int num = recv(i,buf,sizeof(buf),0);
                if(num>0)
                {
                    //正常通信
                    printf("客户端发来的数据：%s\n",buf);
                    //给客户端：回复数据(此处是把数据又发了回去)
                    send(i,buf,strlen(buf)+1,0);;
                }
                else if(num == 0)
                {
                    //客户端断开了连接
                    printf("客户端断开了连接\n");
                    //先从检测的完整的集合中将这个cfd删除
                    FD_CLR(i,&bkset);
                    //关闭通信的cfd
                    close(i);
                }
                else
                {
                    perror("read");
                    exit(0);
                }
            }
        }
    }
    return 0;
}
