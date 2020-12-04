#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>

// 读缓冲区回调
void read_cb(struct bufferevent *bev, void *arg)
{
    char buf[1024] = {0};
    bufferevent_read(bev, buf, sizeof(buf));
    printf("\nclient say: %s", buf);

    // 发数据给客户端
    char *p = "我已经收到了你发送的数据!";
    bufferevent_write(bev, p, strlen(p) + 1);
}

// 写缓冲区回调
void write_cb(struct bufferevent *bev, void *arg)
{
    printf("I am Server's write_cb() ...\n");
}

// 事件
void event_cb(struct bufferevent *bev, short events, void *arg)
{
    if (events & BEV_EVENT_EOF)
    {
        printf("disconnected with client...\n");
    }
    else if (events & BEV_EVENT_ERROR)
    {
        printf("some other error\n");
    }

    bufferevent_free(bev);
    printf("free server's communication bufferevent...\n");
}

void cb_listener(
    struct evconnlistener *listener,
    evutil_socket_t cfd, //accept()的返回值
    struct sockaddr *addr,
    int len, void *ptr)
{
    printf("a new client connected with me!\n");

    // 把通信的cfd,通过bufferevent进行封装(即封装为一个事件)
    struct event_base *base = (struct event_base *)ptr;
    struct bufferevent *bev;
    bev = bufferevent_socket_new(base, cfd, BEV_OPT_CLOSE_ON_FREE);

    // 给bufferevent缓冲区设置回调
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
    bufferevent_enable(bev, EV_READ);
}

int main(int argc, const char *argv[])
{
    struct event_base *base = event_base_new();

    // init serverAddr
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9876);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    //创建监听套接字lfd + 绑定bind + 监听listen + 接收连接请求accept
    struct evconnlistener *listener;
    listener = evconnlistener_new_bind(base, cb_listener, base,
                                       LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
                                       5, (struct sockaddr *)&serv, sizeof(serv));

    event_base_dispatch(base);

    evconnlistener_free(listener);
    event_base_free(base);

    return 0;
}