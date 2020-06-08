// 2. ʹ�ö��̲߳����߳�֮���Ƿ���ȫ�ֱ���
// 		ʹ��n���߳�����, ÿ���߳���1000����, �����յĽ��
// 			��Ҫ����

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>

#define MAX 100
int number;//ȫ�ֱ���
//3.1�����廥����
pthread_mutex_t mutex;


void* childFunc1(void* arg)
{
    for(int i=0;i<MAX;++i)
    {

        //3.4.1������
        pthread_mutex_lock(&mutex);
        
        int cur = number;
        int a = cur;
        int b = a;
        int c = b;
        a++;
        b = a;
        b++;
        c = b;
        usleep(10);//˯10u��
        c--;
        cur = c;
        number = cur;
        printf("Thread A .tid = %lu,number = %d\n",pthread_self(),number);
       
        //3.4.2������
        pthread_mutex_unlock(&mutex); 
    }
    return NULL;
}
void* childFunc2(void* arg)
{
    for(int i=0;i<MAX;++i)
    {

        //3.4.1������
        pthread_mutex_lock(&mutex);
        
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B .tid = %lu,number = %d\n",pthread_self(),number);
       
        //3.4.2������
        pthread_mutex_unlock(&mutex); 
      
        usleep(10);//˯10u��
    }
    return NULL;
}
int main()
{
    //3.2����ʼ��������
    pthread_mutex_init(&mutex,NULL);

    //1�������������߳�
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,childFunc1,NULL);
    pthread_create(&tid2,NULL,childFunc2,NULL);
    //2����������Դ����
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    //3.3������ʹ�õ�ʱ�����ٻ�����
    pthread_mutex_destroy(&mutex);
    return 0;
}


