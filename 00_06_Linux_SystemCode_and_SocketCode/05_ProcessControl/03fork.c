//孤儿进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int number = 10;

    pid_t pid = fork();

    if (pid > 0)
    {
        //父进程
        printf("I am parent process, pid = %d, ppid = %d\n", getpid(), getppid());
        printf("pid == %d\n", pid);
        printf("parent process : number == %d\n", number);
        number += 100;
        printf("parent process : number == %d\n", number);
    }
    else if (0 == pid)
    {
        //子进程
        sleep(1);
        printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
        printf("child process : number == %d\n", number);
        number += 10;
        printf("child process : number == %d\n", number);
    }
    else if (-1 == pid)
    {
        perror("fork");
    }

    for (int i = 0; i < 3; ++i)
    {
        printf("i = %d\n", i);
    }
    sleep(10);
    return 0;
}
