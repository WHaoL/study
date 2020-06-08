#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//1.2、子线程的回调函数
//子线程的代码
void* childFunc(void* arg)
{
    printf("child thread tid：%ld\n",pthread_self());
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
    //2、父/主线程的代码
    printf("主/父线程 的 tid：%ld\n",pthread_self());
    for(int i=0;i<5;++i)
    {
        printf("i = %d\n",i);
    }//循环执行完毕，主线程就退出了
    
    //3、让主线程睡一秒，防止虚拟地址空间被销毁
    //sleep(1);//主线程和子线程共享虚拟地址空间，所以让主线程sleep一秒
             //这样虚拟地址空间就可以多维持一秒，用来给子线程使用
             //子线程执行完毕，子线程退出
             //主线程睡醒了之后，主线程退出，整个虚拟地址空间就没有了
    
    //4、退出主线程，对子线程没有影响
    pthread_exit(NULL);
    return 0;
}


