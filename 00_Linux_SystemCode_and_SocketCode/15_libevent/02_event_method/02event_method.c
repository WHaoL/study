#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <event2/event.h>

int main()
{
    const char** methods = event_get_supported_methods();
    printf("支持的IO转接模型/函数: \n");
    for(int i=0; methods[i] != NULL; ++i)
    {
        printf("    %s\n", methods[i]);
    }

    // 查看当前Linux使用的IO转接模型
    // 创建结构体变量
    struct event_base* base = event_base_new();
    printf("current IO mode: %s\n", event_base_get_method(base));

    pid_t pid = fork();
    if(pid > 0)
    {
        // 父进程
    }
    else if(pid == 0)
    {
        // 子进程
        // base 实例不能直接使用
		// 需要调用event_reinit进行重新初始化
        event_reinit(base);

    }
    return 0;
}
