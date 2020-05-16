//# 8个线程操作同一个全局变量
//	3个线程不定时写同一全局资源，
//	5个线程不定时读同一全局资源
// 		1.查看不加锁结果
//		2.查看加锁之后的结果


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>

#define MAX 100
int number = 0;

//3.1、定义一把锁
pthread_rwlock_t rwlock;

void* writeNum(void* arg)
{
    while(1)
    {
        //4.1、加写锁
        pthread_rwlock_wrlock(&rwlock);
        number++;
        printf("write ++++ ：%ld,%d\n",pthread_self(),number);
        
        //4.2、解开锁
        pthread_rwlock_unlock(&rwlock);
        
        usleep(250);
    }
    return NULL;
}
void* readNum(void* arg)
{
    while(1)
    {
        //4.1、加读锁
        pthread_rwlock_rdlock(&rwlock);
        printf("read **** ：%ld,%d\n",pthread_self(),number);
        //4.2、解开锁
        pthread_rwlock_unlock(&rwlock);
       
        usleep(250);
    }
    return NULL;
}
int main()
{
    //3.2、初始化读写锁
    pthread_rwlock_init(&rwlock,NULL);

    //1、创建线程--5个读，3个写线程
    pthread_t rtid[5],wtid[3];
    for(int i=0;i<3;++i)
    {
        pthread_create(&wtid[i],NULL,writeNum,NULL);
        pthread_detach(wtid[i]);//线程分离--子线程不需要我们负责回收
    }
    for(int i=0;i<5;++i)
    {
        pthread_create(&rtid[i],NULL,readNum,NULL);
        pthread_detach(rtid[i]);//线程分离--子线程不需要我们负责回收
    }
    
    //3.3、回收子线程资源
    for(int i=0;i<3;++i)
    {
        pthread_join(wtid[i],NULL);
    }
    for(int i=0;i<5;++i)
    {
        pthread_join(rtid[i],NULL);
    }
    //3.4、销毁读写锁
    pthread_rwlock_destroy(&rwlock);
    //2、主线程退出，不影响子线程
    pthread_exit(NULL);
    return 0;
}


