#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    //1.创建通信的套接字
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定IP、Port
    struct sockaddr_in addr;
    addr.sin_port = htons(9898);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    int ret = bind(lfd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret == -1)
    {
        perror("bind");
        exit(0);
    }
    //3.设置监听
    ret = listen(lfd,128);
    if(ret == -1)
    {
        perror("listen");
        exit(0);
    }
    //4.创建epoll树
    int epfd = epoll_create(1);
    if(epfd == -1)
    {
        perror("epoll_create");
        exit(0);
    }
    //5.初始化epoll树
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&ev);//将lfd挂到树上
    
    //创建结构体数组：存储epoll传出的fd及其状态
    struct epoll_event evs[1024];
    int lenevs = sizeof(evs)/sizeof(evs[0]);
    //6.检测fd
    int NNN = 1;
    while(1)
    {
        int num = epoll_wait(epfd,evs,lenevs,-1);

        //测试epoll的ET模式
        //epoll每返回一次，下面的输出语句就被调用一次
        printf("epoll共返回：%d\n次",NNN++);

        for(int i=0;i<num;++i)
        {
            int curfd = evs[i].data.fd;
            //6.连接请求
            if(lfd == curfd)//建立连接
            {
                struct sockaddr_in cliaddr;
                int lencli = sizeof(cliaddr);
                int cfd = accept(lfd,(struct sockaddr*)&addr,&lencli);
                //将cfd设置为非阻塞
                int flag = fcntl(cfd,F_GETFL);
                flag |= O_NONBLOCK;
                fcntl(cfd,F_SETFL,flag);
                //将这个通信的cfd挂到树上
                ev.events = EPOLLIN | EPOLLET;//改为了ET模式！！！
                ev.data.fd = cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);
            }
            //6.2通信
            else
            {
                char buf[5];
#if 0
                int num = recv(curfd,buf,sizeof(buf),0);
                if(num > 0)
                {
                    printf("客户端发来的数据：%s\n",buf);
                    send(curfd,buf,strlen(buf)+1,0);
                }
                else if(num == 0)
                {
                    printf("客户端已经断来连接...\n");
                    //将curfd从书上摘掉
                    epoll_ctl(epfd,EPOLL_CTL_DEL,curfd,NULL);
                    //并：关闭curfd 
                    close(curfd);
                }
                else
                {
                    perror("recv");
                    exit(0);
                }
#else
                int num = 0;
                while((num = recv(curfd,buf,sizeof(buf),0))>0)
                {
                    //读出的数据直接写到终端进行显示
                    write(STDOUT_FILENO,buf,num);

                    //接收的数据发送给客户端
                    send(curfd,buf,num,0);
                }
                if(num == 0)
                {
                    printf("客户端已经断开连接...\n");
                }
                else
                {
                    if(errno == EAGAIN | errno == EWOULDBLOCK)
                    {
                        printf("数据已经读完...\n");
                    }
                    else
                    {
                        printf("有异常,game over！！！\n");
                        perror("recv");
                        exit(0);
                    }
                }

#endif
            }
        }
    }
    close(lfd);
    return 0;
}

