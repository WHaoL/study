//父子进程通过匿名管道进行进程间通信
/* 
 *     父子进程间通信, 实现 ps aux 
 *      - 子进程执行shell命令: ps aux
 *      - 父进程中输出命令结果
 *                  */
//程序执行完毕会阻塞在read处，因为管道中没数据时会读阻塞
//改进版-->见"04parent_child_pipe.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    //1、首先在父进程中创建匿名管道，获得两个文件描述符
    //返回值: 为0说明创建匿名管道成功了;为-1说明失败了
    int fd[2];
    int ret = pipe(fd);
    if (-1 == ret)
    {
        perror("pipe");
        exit(-1);
    }

    //2、在父进程中创建子进程，同时那两个文件描述符被拷贝到子进程中
    pid_t pid = fork();

    if (pid > 0)
    {
        //父进程--读管道
        //1、关闭父进程的管道的写端文件描述符
        close(fd[1]);

        //2、使用管道的读端进行数据的读取

#if 1
        // block : 父进程接收数据，，重定向输出终端，并调用 grep bash
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "bash", NULL);
        perror("execlp");
        close(fd[0]);
        exit(-1);
#else
        // block : 父进程接收数据，并打印到终端
        char buf[1024] = {0};
        while (1)
        {
            memset(buf, 0, sizeof(buf));
            int NUM = read(fd[0], buf, sizeof(buf) - 1);
            if (NUM > 0)
            {
                printf("%s\n", buf);
            }
            else if (NUM == 0)
            {
                printf("数据读取完毕！\n");
                break;
            }
            else if (NUM < 0)
            {
                perror("read");
                exit(-1);
            }
        }
        close(fd[0]); //关闭父进程的管道的读端
#endif
    }
    else if (pid == 0)
    {
        //子进程--写管道
        //1、关闭子进程的管道的读端文件描述符
        close(fd[0]);

        //2、重定向：将子进程的输出重定向到管道的写端
        dup2(fd[1], STDOUT_FILENO);

        //3、使用execlp，使子进程调用ps aux
        execlp("ps", "ps", "aux", NULL);

        //如果execlp执行失败
        perror("execlp");
        exit(-1);
    }
    else if (pid == -1)
    {
        perror("fork");
        exit(-1);
    }
    return 0;
}
/*
       #include <unistd.h>
	   
       pid_t fork(void);
	   
RETURN VALUE
    On success, the PID of the child process is returned in the parent, and 0 is returned in the  child.   
	On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.
*/
