/*

   写程序:
   在父进程中创建5个子进程, 使用waitpid回收这些子进程资源
   这是错误的, 创建出的子进程个数>5
   如果是子进程, 不要再创建子进程了
   for(int i=0; i<5; ++i)
   {
		fork();
   }
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    //1、创建5个子进程
    for(int i=0;i<5;++i)
    {
        pid = fork();
        //只有父进程才创建子进程
        //如果是子进程，不继续执行接下来的循环,即子进程不创建子进程
        if(0 == pid)
        {
            break;
        }
    }
    //2、逻辑处理--分为:父进程和子进程部分
    if(pid>0)
    {
        //父进程回收子进程资源
        while(1)
        {
            pid_t ret = waitpid(-1,NULL,WNOHANG);//非阻塞
            //pid_t ret = waitpid(-1,NULL,0);//阻塞
            if(ret > 0)
            {
                printf("我是父进程pid= %d , 回收的子进程的pid= %d\n", getpid(), ret);
            }
            else if(0 == ret)
            {
                printf("还有子进程正在运行\n");
            }
            else
            {
                //ret === -1
                printf("所有子进程都已经回收\n");
                break;
            }
        }
    }
    else if(0 == pid)
    {
        //子进程
        printf("我是子进程，我的pid= %d\n", getpid());
        sleep(1);
        return 0;
    }
    return 0;
}









