#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

//6.1.1、定义条件变量
pthread_cond_t cond;

//4.1、创建互斥锁
pthread_mutex_t mutex;

//2.1、定义链表节点的结构体 
struct Node 
{
    int number;//存储的数据
    struct Node* next;//指向下一个节点的指针
};
//2.2、定义头结点指针
//生产者和消费者通过它来操作容器
struct Node* head = NULL;

//3.1、线程处理函数
void* producer(void* arg)
{
    while(1)
    {
        //5.1、互斥锁：加锁
        pthread_mutex_lock(&mutex);

        //3.1.1、生成节点
        struct Node* pnew = (struct Node*)malloc(sizeof(struct Node));
        //3.1.2、初始化节点
        pnew->number = rand()%1000;
        pnew->next = NULL;
        //3.1.3、添加到表头
        pnew->next = head;
        head = pnew;
        
        //5.1、互斥锁：解锁
        pthread_mutex_unlock(&mutex);

        sleep(rand()%3);

        //6.2、生产了一个之后：唤醒阻塞在条件变量上的线程
        pthread_cond_signal(&cond);
    }
    return NULL;
}
//3.1、线程处理函数
void* customer(void* arg)
{
    while(1)
    {
        //5.1、互斥锁：加锁
        pthread_mutex_lock(&mutex);

        //3.2.1、判断链表是否为空
        // 多线程情况下:容器空时，多个消费者线程同时阻塞在wait函数这儿
        // 当生产者线程同时唤醒好几个阻塞在此处的消费者线程后
        // 当一个解除阻塞的消费者线程去执行下面的代码(删除节点)后
        // 另外一个解除阻塞的消费者线程应该先判断容器是否为空，
        // 因为可能消费了一次后，容器又为空了，不能消费，需继续阻塞线程
        while(head == NULL)
        {
            //链表为空，消费者就不能消费，消费者线程阻塞
            //6.1、使用条件变量：阻塞消费者线程
            // 线程走到这个函数的位置：线程阻塞；这个线程已经成功对互斥锁加锁 
            // 这个wait函数干两件事：
            // 1.(阻塞线程之前)
            // 假设这个线程阻塞在条件变量这儿，整个程序有可能死锁
            // 因此这个wait函数在阻塞线程之前，会自动将线程对应的互斥锁解锁
            // 2.(解除阻塞线程之后)
            // 当线程解除阻塞，wait函数会将线程对应的互斥锁再加锁 
            pthread_cond_wait(&cond,&mutex);         
        }
        //3.2.2、链表不为空,开始消费
        struct Node* pNode = head;
        head = head->next;
        printf("删除节点的number：%d，%ld\n",pNode->number,pthread_self());
        free(pNode);//删除节点
        
        //5.1、互斥锁：解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main()
{

    //4.2、初始化互斥锁
    pthread_mutex_init(&mutex,NULL);

    //6.1.2、初始化条件变量
    pthread_cond_init(&cond,NULL);

    //1.1、创建线程--5个读，5个写线程
    pthread_t ptid[5];//生产者
    pthread_t ctid[5];//消费者
    for(int i=0;i<5;++i)
    {
        pthread_create(&ptid[i],NULL,producer,NULL);
        pthread_create(&ctid[i],NULL,customer,NULL);
    }
    
    //1.2、回收子线程资源
    for(int i=0;i<5;++i)
    {
        pthread_join(ptid[i],NULL);
        pthread_join(ctid[i],NULL);
    }
    
    //4.3、销毁互斥锁
    pthread_mutex_destroy(&mutex);

    //6.1.3、销毁条件变量
    pthread_cond_destroy(&cond);
    
    return 0;
}


