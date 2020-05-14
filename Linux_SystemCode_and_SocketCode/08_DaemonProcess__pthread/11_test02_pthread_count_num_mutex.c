// 2. 使用多线程测试线程之间是否共享全局变量
// 		使用n个线程数数, 每个线程数1000个数, 看最终的结果
// 			需要加锁

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>

#define MAX 100
int number;//全局变量
//3.1、定义互斥锁
pthread_mutex_t mutex;


void* childFunc1(void* arg)
{
    for(int i=0;i<MAX;++i)
    {

        //3.4.1、加锁
        pthread_mutex_lock(&mutex);
        
        int cur = number;
        int a = cur;
        int b = a;
        int c = b;
        a++;
        b = a;
        b++;
        c = b;
        usleep(10);//睡10u秒
        c--;
        cur = c;
        number = cur;
        printf("Thread A .tid = %lu,number = %d\n",pthread_self(),number);
       
        //3.4.2、解锁
        pthread_mutex_unlock(&mutex); 
    }
    return NULL;
}
void* childFunc2(void* arg)
{
    for(int i=0;i<MAX;++i)
    {

        //3.4.1、加锁
        pthread_mutex_lock(&mutex);
        
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B .tid = %lu,number = %d\n",pthread_self(),number);
       
        //3.4.2、解锁
        pthread_mutex_unlock(&mutex); 
      
        usleep(10);//睡10u秒
    }
    return NULL;
}
int main()
{
    //3.2、初始化互斥锁
    pthread_mutex_init(&mutex,NULL);

    //1、创建两个子线程
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,childFunc1,NULL);
    pthread_create(&tid2,NULL,childFunc2,NULL);
    //2、阻塞，资源回收
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    //3.3、不再使用的时候，销毁互斥锁
    pthread_mutex_destroy(&mutex);
    return 0;
}


