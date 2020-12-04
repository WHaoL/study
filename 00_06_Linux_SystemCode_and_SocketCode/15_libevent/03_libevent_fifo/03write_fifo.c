// 03write_fifo.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <event2/event.h>


void cb_write(evutil_socket_t fd, short what, void *arg)
{
    // 写数据
    static int num = 0;
    char buf[1024] = {0};
    sprintf(buf, "hello, %d\n", num++);
    write(fd, buf, strlen(buf)+1);
	
    // 当前监测的是写事件吗
    printf("what is write: %s\n", what & EV_WRITE ? "yes" : "no");
    sleep(5);
}

int main()
{
    // 1. 打开管道文件
    int fd = open("myfifo", O_WRONLY);
    if(fd == -1)
    {
        perror("open");
        exit(0);
    }

    // 2. 将这个fd封装成事件
	// 2.1创建事件处理框架
    struct event_base* base = event_base_new();
	// 2.2创建事件
    struct event* w_ev = event_new(base, fd, EV_WRITE|EV_PERSIST, cb_write, NULL);
  
	// 3.将事件添加到处理框架上
    event_add(w_ev, NULL);
    
	// 4.启动事件循环
    event_base_dispatch(base);

    // 5.资源释放
    event_free(w_ev);
    event_base_free(base);

    return 0;
}