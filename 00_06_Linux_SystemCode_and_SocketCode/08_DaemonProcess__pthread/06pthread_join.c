#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//6.1、子线程退出时的传出数据
struct Info
{
    char name[24];
    int age;
};

//7.2、线程与线程之间共享全局数据区、堆区、(栈区不共享)
//此处把这个变量声明为全局变量/堆区变量都是可以的
//struct Info info;

//1.2、子线程的回调函数
//子线程的代码
void *childFunc(void *arg)
{
    //8.2、还原数据类型
    struct Info *info = (struct Info *)arg;

    printf("child thread tid：%ld\n", pthread_self());
    for (int i = 0; i < 30; ++i)
    {
        printf("child_thread i = %d\n", i);
        //5、满足某些条件或者是子线程出现错误时，让子线程退出
        //对其他线程没有影响
        if (i == 10)
        {
            //6.2、子进程退出时的传出数据

            //struct Info info;
            //7.1、不能把这个栈区的数据传给父线程
            //因为：线程与线程之间，栈区不共享
            //子线程退出，属于它的栈区就被释放了

            strcpy(info->name, "lilei");
            info->age = 24;
            //pthread_exit(&info);//传出的是全局变量的地址，是可以的
            pthread_exit(info); //传出的是全局变量的地址，是可以的
            //谁回收子线程，谁就能接收到子线程的传出数据
        }
    } //循环执行完毕，子线程就退出了
}

int main()
{
    //1.1、创建线程
    pthread_t ptid;

    //8.1、主线程回收子线程资源时，因为主线程后死
    //所以：子线程传回的地址，可以是主线程栈区的地址
    struct Info info; //在主线程的栈区创建这个变量

    pthread_create(&ptid, NULL, childFunc, &info);

    //2、父/主线程的代码
    printf("主/父线程 的 tid：%ld\n", pthread_self());
    for (int i = 0; i < 5; ++i)
    {
        printf("i = %d\n", i);
    } //循环执行完毕，主线程就退出了

    //3、让主线程睡一秒，防止虚拟地址空间被销毁
    //sleep(1);
    //	主线程和子线程共享虚拟地址空间，所以让主线程sleep一秒
    //	这样虚拟地址空间就可以多维持一秒，用来给子线程使用
    //	子线程执行完毕，子线程退出
    //	主线程睡醒了之后，主线程退出，整个虚拟地址空间就没有了

    //6、回收子线程资源
    //谁回收子线程，谁就能接收到子线程的传出数据
    struct Info *pt;
    pthread_join(ptid, (void **)&pt);
    printf("name：%s,age：%d\n", pt->name, pt->age);

    //4、退出主线程，对子线程没有影响
    pthread_exit(NULL);
    return 0;
}
