#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/epoll.h>

int main()
{
    //1.创建通信的套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        exit(0);
    }

    //2.绑定IP、Port
    struct sockaddr_in addr;
    addr.sin_port = htons(9898);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
        exit(0);
    }

    //3.设置监听
    ret = listen(lfd, 128);
    if (ret == -1)
    {
        perror("listen");
        exit(0);
    }

    //4.创建epoll树
    int epfd = epoll_create(1);
    if (epfd == -1)
    {
        perror("epoll_create");
        exit(0);
    }

    //5.初始化epoll树
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = lfd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev); //将lfd挂到树上

    //创建结构体数组：存储epoll传出的fd及其状态
    struct epoll_event evs[1024];
    int lenevs = sizeof(evs) / sizeof(evs[0]);

    //6.检测fd
    while (1)
    {
        int num = epoll_wait(epfd, evs, lenevs, -1);
        for (int i = 0; i < num; ++i)
        {
            int curfd = evs[i].data.fd;
            //6.连接请求
            if (lfd == curfd) //建立连接
            {
                struct sockaddr_in cliaddr;
                int lencli = sizeof(cliaddr);
                int cfd = accept(lfd, (struct sockaddr *)&addr, &lencli);
                //将这个通信的cfd挂到树上
                ev.events = EPOLLIN;
                ev.data.fd = cfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
            }
            //6.2通信
            else
            {
                char buf[1024];
                int num = recv(curfd, buf, sizeof(buf), 0);
                if (num > 0)
                {
                    printf("客户端发来的数据：%s\n", buf);
                    send(curfd, buf, strlen(buf) + 1, 0);
                }
                else if (num == 0)
                {
                    printf("客户端已经断来连接...\n");
                    //将curfd从书上摘掉
                    epoll_ctl(epfd, EPOLL_CTL_DEL, curfd, NULL);
                    //并：关闭curfd
                    close(curfd);
                }
                else
                {
                    perror("recv");
                    exit(0);
                }
            }
        }
    }
    close(lfd);
    return 0;
}