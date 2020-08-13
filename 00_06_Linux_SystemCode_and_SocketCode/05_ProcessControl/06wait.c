#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // 有一个父进程, 5个子进程(兄弟)
    pid_t pid;
    for (int i = 0; i < 5; ++i)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }

    if (pid > 0)
    {
        while (1)
        {
            printf("parent, pid = %d\n", getpid());
            int s;
            int ret = wait(&s);
            if (WIFEXITED(s))
            {
                printf("退出的状态码: %d\n", WEXITSTATUS(s));
            }
            if (WIFSIGNALED(s))
            {
                printf("被信号 %d 干掉了\n", WTERMSIG(s));
            }
            printf("child pid = %d died!!!!!!\n", ret);
            sleep(1);
        }
    }
    else if (pid == 0)
    {
        while (1)
        {
            printf("child, pid = %d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}
