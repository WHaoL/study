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
int number = 0;

void* childFunc1(void* arg)
{
    for(int i=0;i<MAX;++i)
    {
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
    }
    return NULL;
}
void* childFunc2(void* arg)
{
    for(int i=0;i<MAX;++i)
    {
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B .tid = %lu,number = %d\n",pthread_self(),number);
        usleep(10);//睡10u秒
    }
    return NULL;
}
int main()
{
    //1、创建两个子线程
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,childFunc1,NULL);
    pthread_create(&tid2,NULL,childFunc2,NULL);
    //2、阻塞，资源回收
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}

