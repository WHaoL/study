//父子进程通过匿名管道进行进程间通信
/* 
 *     父子进程间通信, 实现 ps aux 
 *      - 子进程执行shell命令: ps aux
 *      - 父进程中输出命令结果
 *                  */ 
//程序执行完毕会阻塞在read处，因为管道中没数据时会读阻塞
//改进版-->见"04parent_child.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);//1、首先在父进程中创建匿名管道，获得两个文件描述符
    if(-1 == ret)
    {//返回值为0说明创建匿名管道成功了，为-1说明失败了
        perror("pipe");
        exit(0);
    }

    pid_t pid = fork();//2、在父进程中创建子进程，同时那两个文件描述符被拷贝到子进程中
    if(pid > 0 )
    {
        //父进程--读管道
        //1、关闭父进程的管道的写端文件描述符
        close(fd[1]);
        //2、使用管道的读端进行数据的读取
        char buf[1024]={0};
        while(1)
        {
            memset(buf,0,sizeof(buf));
            int NUM = read(fd[0],buf,sizeof(buf)-1);
            if(0 == NUM)
            {
                printf("数据已经读完了\n");
                break;
            }
            printf("%s",buf);
        }
        close(fd[0]);//关闭父进程的管道的读端
    }
    else if(pid == 0)
    {
        //子进程--写管道
        //1、关闭子进程的管道的读端文件描述符
        close(fd[0]);
        //2、重定向：将输出重定向到管道的写端
        dup2(fd[1],STDOUT_FILENO);
        //3、使用execlp，使子进程调用ps aux
        execlp("ps","ps","aux",NULL);
        perror("execlp");//execlp执行失败
    }
    else if(pid == -1)
    {
        perror("fork");
        exit(0);
    }
    return 0;
}

