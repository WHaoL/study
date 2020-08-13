//回收子进程资源
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    pid_t pid = fork();
    if (pid > 0)
    {
        //父进程
        printf("我是父进程。我的进程ID：%d\n", getpid());
        pid_t pid2 = wait(NULL);
        printf("被回收的子的进程ID：%d\n", pid2);
        printf("我是父进程。我的进程ID：%d\n", getpid());
    }
    else if (0 == pid)
    {
        //子进程
        printf("我是子进程。我的进程ID：%d，我爹的PID：%d\n", getpid(), getppid());
        sleep(5);
        printf("我是子进程。我的进程ID：%d，我爹的PID：%d\n", getpid(), getppid());
    }
    else if (-1 == pid)
    {
        perror("fork");
    }
    return 0;
}
