// 03read_fifo.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <event2/event.h>


void cb_read(evutil_socket_t fd, short what, void *arg)
{
    // 读数据
    char buf[1024] = {0};
    read(fd, buf, sizeof(buf));
    printf("recv data: %s\n", buf);
    // 当前是不是监测的读事件
    printf("what is read: %s\n", what & EV_READ ? "yes" : "no");
    // 当前是否超时
    printf("what is timeout: %s\n", what & EV_TIMEOUT ? "yes" : "no");
}

int main()
{
    // 1. 打开管道文件
    int fd = open("myfifo", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(0);
    }

    // 2. 将这个fd封装成事件
    // 2.1创建事件处理框架
    struct event_base* base = event_base_new();
    // 2.2创建事件
    struct event* r_ev = event_new(base, fd, EV_READ|EV_PERSIST, cb_read, NULL);
    
    // 3.uct timeval val;
    val.tv_sec = 2;
    val.tv_usec = 0;
	// event_add(r_ev, NULL);
    event_add(r_ev, &val);   // 超时时长2s, 2s之后回调函数会被强制执行
    
    // 4.事件循环
    event_base_dispatch(base);

	// 结束事件循环后
    // 5.资源释放
    event_free(r_ev);//释放事件
    event_base_free(base);//释放事件框架

    return 0;
}
