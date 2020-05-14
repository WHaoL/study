#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//1.2、子线程的回调函数
//子线程的代码
void* childFunc(void* arg)
{
    printf("child thread tid:%ld\n",pthread_self());
    for(int i=0;i<30;++i)
    {
        printf("child i = %d\n",i);
        //5、满足某些条件或者是子线程出现错误时，让子线程退出
        //对其他线程没有影响
        if(i == 10)
        {
            pthread_exit(NULL);
        }
    }//循环执行完毕，子线程就退出了
}

int main()
{
    //1.1、创建线程
    pthread_t ptid;
    pthread_create(&ptid,NULL,childFunc,NULL);
    
    //9.1、子线程创建之后，进行线程分离
    //线程分离之后，子线程资源由系统释放，不需要我们管
    pthread_detach(ptid);

    //10、线程取消，杀死子线程
    pthread_cancel(ptid);

    //2、父/主线程的代码
    printf("主/父线程 的 tid:%ld\n",pthread_self());
    for(int i=0;i<5;++i)
    {
        printf("i = %d\n",i);
    }//循环执行完毕，主线程就退出了

    //4、退出主线程，对子线程没有影响
    pthread_exit(NULL);
    return 0;
}


