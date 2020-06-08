//僵尸进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{

    pid_t pid  = fork();
    if(pid>0)
    {
        //父进程
        while(1)
        {
            printf("I am parent process, pid = %d\n", getpid());
            sleep(1);
        }
    }
    else if(0 == pid)
    {
        //子进程
        printf("I am child process, pid = %d , ppid = %d\n", getpid(),getppid());
        sleep(1);
        printf("I am child process, pid = %d , ppid = %d\n", getpid(),getppid());
    }
    else if(-1 == pid)
    {
        perror("fork");
    }
	
	for(int i=0; i<3; ++i)
    {
        printf("i = %d\n", i);
    }

    return 0;
}

