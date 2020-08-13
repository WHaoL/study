//僵尸进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{

    pid_t pid = fork();
    if (pid > 0)
    {
        //父进程
        //while (1)
        {
            sleep(10); //父进程活的比子进程长，就会负责回收子进程的PCB
            printf("I am parent process, pid = %d\n", getpid());
        }
    }
    else if (0 == pid)
    {
        //子进程
        printf("I am child process, pid = %d , ppid = %d\n", getpid(), getppid());
        sleep(1);
        printf("I am child process, pid = %d , ppid = %d\n", getpid(), getppid());
    }
    else if (-1 == pid)
    {
        perror("fork");
    }

    for (int i = 0; i < 3; ++i)
    {
        printf("pid= %d , i = %d\n", getpid(), i);
    }

    return 0;
}
