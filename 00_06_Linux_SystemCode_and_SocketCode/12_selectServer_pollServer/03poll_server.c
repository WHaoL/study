// 03poll_server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <poll.h>

int main()
{
    //1.创建监听的套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定本地IP、端口
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9898);
    addr.sin_addr.s_addr = INADDR_ANY;
    int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
        exit(0);
    }
    //3.设置监听
    listen(lfd, 128);
    if (ret == -1)
    {
        perror("listen");
        exit(0);
    }
    //检测的集合：结构体数组
    struct pollfd fds[1024];
    int lenfds = sizeof(fds) / sizeof(fds[0]);
    for (int i = 0; i < lenfds; ++i)
    {
        fds[i].fd = -1; //此处使用-1,代表当前数组元素没有被专用
        fds[i].events = POLLIN;
    }
    fds[0].fd = lfd; //监听的文件描述符
    int maxfd = lfd; //文件描述符的范围
    while (1)
    {
        int ret = poll(fds, maxfd + 1, -1);
        //poll解除阻塞，说明有连接请求、或者有通信
        //判断有无连接请求
        if (fds[0].revents & POLLIN)
        {
            struct sockaddr_in cliaddr;
            int lencli = (int)sizeof(cliaddr);
            int cfd = accept(lfd, (struct sockaddr *)&cliaddr, &lencli);
            for (int i = lfd + 1; i < maxfd + 1; ++i)
            {
                if (fds[i].fd == -1)
                {
                    fds[i].fd = cfd; //把通信的文件描述符放到集合中
                    break;
                }
            }
            //更新文件描述符的范围
            maxfd = maxfd > cfd ? maxfd : cfd;
        }
        //通信
        for (int i = lfd + 1; i < maxfd + 1; ++i)
        {
            struct pollfd *p = &fds[i];
            if (p->revents & POLLIN)
            {
                char buf[1024];
                int num = read(p->fd, buf, sizeof(buf));
                if (num > 0)
                {
                    printf("客户端说：%s\n", buf);
                    write(p->fd, buf, strlen(buf) + 1);
                }
                else if (num == 0)
                {
                    printf("客户端已经断开连接...\n");
                    p->fd = -1;
                }
                else if (num == -1)
                {
                    perror("read");
                    exit(0);
                }
            }
        }
    }
    close(lfd);
    return 0;
}