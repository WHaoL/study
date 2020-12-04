#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <event2/event.h>
#include <event2/bufferevent.h>

// 接收数据操作顺序
// 1. 对方发送数据到客户端的内核缓冲区
// 2. libevent自动把数据，从内核缓冲区读取到libevent的读缓冲区
// 3. 调用用户自定义的read_cb()函数，read_cb()内部调用bufferevent_read()
//    把数据从libevent的读缓冲区，读到用户自定义内存中

// 发送数据操作顺序
// 1.不带缓冲区的事件和终端的标准输入STDIN_FILENO，建立连接
// 2.终端发送数据,到,不带缓冲区的事件
// 3.不带缓冲区的事件检测到有数据到达内核
// 4.调用send_cb()，send_cb()中，先把标准输入数据读到用户自己的内存中，
//   然后调用bufferevent_write()
//   把数据写入到带缓冲区的event的，libevent的写缓冲区中
// 5.数据达到一定的量，libevent会把自己写缓冲区的数据，发送到内核写缓冲区中
// 6.检测到有数据到达内核写缓冲区，会调用write_cb()
//   (其实该函数没有完成什么又有意义的实际逻辑)
// 7. libevent 负责把数据从内核中发送出去(发送给服务器)

void read_cb(struct bufferevent *bev, void *arg)
{
    char buf[1024] = {0};
    bufferevent_read(bev, buf, sizeof(buf));
    printf("Server say: %s\n", buf);
}

void write_cb(struct bufferevent *bev, void *arg)
{
    printf("I am Client's write_cb()\n");
}

void event_cb(struct bufferevent *bev, short events, void *arg)
{
    if (events & BEV_EVENT_EOF)
    {
        printf("disconnected with server...\n");
    }
    else if (events & BEV_EVENT_ERROR)
    {
        printf("some other error\n");
    }
    else if (events & BEV_EVENT_CONNECTED)
    {
        printf("connected with server !\n");
        return;
    }

    bufferevent_free(bev);
    printf("free client's communication bufferevent...\n");
}

void send_cb(evutil_socket_t fd, short what, void *arg)
{
    char buf[1024] = {0};
    //printf("请输入要发送的数据: \n");
    read(fd, buf, sizeof(buf));

    struct bufferevent *bev = (struct bufferevent *)arg;
    bufferevent_write(bev, buf, strlen(buf) + 1);
}

int main(int argc, const char *argv[])
{
    // 事件处理框架
    struct event_base *base;
    base = event_base_new();

    //带缓冲区的事件
    struct bufferevent *bev;
    bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    //指定为-1时，会帮助我们创建一个用于通信的文件描述符

    // 连接服务器
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9876);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
    bufferevent_socket_connect(bev, (struct sockaddr *)&serv, sizeof(serv));

    // 设置回调
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
    bufferevent_enable(bev, EV_READ);

    // 不带缓冲区的事件
    struct event *ev = event_new(base, STDIN_FILENO,
                                 EV_READ | EV_PERSIST,
                                 send_cb, bev); //有输入就调用回调函数，把数据发送给server
    event_add(ev, NULL);
    event_base_dispatch(base);

    event_free(ev);
    event_base_free(base);

    return 0;
}