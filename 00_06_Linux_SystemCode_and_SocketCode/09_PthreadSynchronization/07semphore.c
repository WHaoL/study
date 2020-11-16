#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>

//4.1、定义信号量变量
sem_t psem; //控制生产者的信号量
sem_t csem; //控制消费者的信号量

//6.1、创建互斥锁变量
//添加互斥锁进行线程同步
pthread_mutex_t mutex;

//2.1、定义链表节点的结构体
struct Node
{
    int number;        //存储的数据
    struct Node *next; //指向下一个节点的指针
};
//2.2、定义头结点指针
//生产者和消费者通过它来操作容器
struct Node *head = NULL;

//3.1、线程处理函数
void *producer(void *arg)
{
    while (1)
    {
        //5.1、判断是不是要阻塞线程,即判断能不能生产
        // psem>0 ：psem--
        // psem==0：阻塞
        sem_wait(&psem); //psem里的整数减减

        //7.1、添加互斥锁
        pthread_mutex_lock(&mutex);

        //3.1.1、生成节点
        struct Node *pnew = (struct Node *)malloc(sizeof(struct Node));
        //3.1.2、初始化节点
        pnew->number = rand() % 1000;
        pnew->next = NULL;
        //3.1.3、添加到表头
        pnew->next = head;
        head = pnew;

        printf("add node, number: %d, tid = %ld\n", pnew->number, pthread_self());

        //7.2、解开互斥锁
        pthread_mutex_unlock(&mutex);

        //5.2、生产完了之后，通知消费者去消费
        //csem++
        sem_post(&csem);

        usleep(100);
    }
    return NULL;
}
//3.1、线程处理函数
void *customer(void *arg)
{
    while (1)
    {
        //5.1、判断是不是能消费
        sem_wait(&csem);

        //7.1、添加互斥锁
        pthread_mutex_lock(&mutex);

        //3.2.2、链表不为空,开始消费
        struct Node *pNode = head;
        head = head->next;
        printf("删除节点的number：%d，%ld\n", pNode->number, pthread_self());
        free(pNode); //删除节点

        //7.2、解开互斥锁
        pthread_mutex_unlock(&mutex);

        //5.2、消费了之后，通知生产者去生产
        sem_post(&psem);

        usleep(100);
    }
    return NULL;
}
int main()
{
    //4.2、初始化信号量变量
    sem_init(&psem, 0, 5);
    // >1时，就会出现段错误，因为读写线程数目较多
    // 生产者之间会竞争-共享资源、
    // 消费者之间会竞争-共享资、
    // 生产者和消费者之间也会竞争-共享资
    // 因为：信号量和条件变量只能阻塞线程，涉及到访问共享资源时
    // 一定要加互斥锁做线程同步
    sem_init(&csem, 0, 0);

    //6.2、初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    //1.1、创建线程--5个读，5个写线程
    pthread_t ptid[5]; //生产者
    pthread_t ctid[5]; //消费者
    for (int i = 0; i < 5; ++i)
    {
        pthread_create(&ptid[i], NULL, producer, NULL);
        pthread_create(&ctid[i], NULL, customer, NULL);
    }

    //1.2、回收子线程资源
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(ptid[i], NULL);
        pthread_join(ctid[i], NULL);
    }

    //6.3、释放互斥锁
    pthread_mutex_destroy(&mutex);

    //4.3、释放信号量
    sem_destroy(&psem);
    sem_destroy(&csem);

    return 0;
}