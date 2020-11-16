#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

// 4.1、回调函数, 信号被捕捉之后的处理动作
void recyleChild(int num)
{
    while (1)
    {
        // 回收子进程的资源
        pid_t pid = waitpid(-1, NULL, WNOHANG);
        if (pid > 0)
        {
            printf("child die, pid = %d\n", pid);
        }
        else if (pid == 0)
        {
            printf("child is running...\n");
            break;
        }
        else if (pid == -1)
        {
            printf("all child die\n");
            break;
        }
    }
}

int main()
{
    // 4、注册信号捕捉
    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = recyleChild;
	
    sigaction(SIGCHLD, &act, NULL);

    pid_t pid;
    // 1. 创建子进程, 5个
    for (int i = 0; i < 5; ++i)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }

    if (pid == 0)
    {
        // 2、子进程
        printf("child process, pid = %d\n", getpid());
    }
    else if (pid > 0)
    {

        // 3、父进程
        while (1)
        {
            sleep(1);
            printf("parent process, pid = %d\n", getpid());
        }
    }
    return 0;
}