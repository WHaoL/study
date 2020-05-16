#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void callback(int num)//num 是捕捉到的信号的值
{
    printf("捕捉的信号：%d\n",num);
}

int main()
{
    //1、初始化自定义信号集
    sigset_t myset;
    sigemptyset(&myset);//清空自定义信号集
    sigaddset(&myset,SIGINT);//ctrl+c；2号
    sigaddset(&myset,SIGQUIT);//ctrl+\；3号
    sigaddset(&myset,SIGKILL);//9号,(9(无条件杀死)、19(无条件暂停)不能被捕捉、阻塞、忽略)
    //2、将自定义信号集数据设置到内核阻塞信号集中
    sigset_t old;
    sigprocmask(SIG_BLOCK,&myset,&old);
    //6、在信号产生之前，注册信号捕捉
    //6.1、初始化第二个参数
    struct sigaction act;
    act.sa_handler = callback;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT,&act,NULL);//注册2号信号捕捉
    sigaction(SIGQUIT,&act,NULL);//注册3号信号捕捉
    sigaction(SIGKILL,&act,NULL);//注册9号信号捕捉

    int count = 0;
    while(1)
    {
        count++;
        //3、读未决信号集
        sigset_t curset;
        sigpending(&curset);
        //4、检测未决信号集中各个信号对应的标志位
        for(int i=0;i<31;++i)
        {
            int ret = sigismember(&curset,i+1);
            if(ret == 0)
            {
                printf("0");
            }
            else if(ret == 1)
            {
                printf("1");
            }
        }
        printf("\n");
        if(count == 10)
        {
            //5、解除阻塞
            sigprocmask(SIG_SETMASK,&old,NULL);
            //sigprocmask(SIG_UNBLOCK,&myset,NULL);
        }
        sleep(1);
    }
    return 0;
}

