#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //1、创建子进程, 在子进程中执行execl execlp
    pid_t pid = fork();
    if(pid>0)
    {
        //父进程
        printf("我是02execl_execlp中的父进程\n");
    }
    else if(0 == pid)
    {
        //子进程
        //execl("/home/lwh/Desktop/codes/day05/01a.out","01a.out",NULL);
        //execl("/bin/ps","/bin/ps","aux",NULL);
		//     可执行程序 、别名、参数、NULL
        execlp("ps","ps aux","aux",NULL);
		perror("execl");
        printf("hello I am child process !!!!: Execution execlp() failed \n");
    }
	for(int i=0; i<5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    return 0;
}

