#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
//当定时时间到达时，会发送信号--> 导致进程终止/死亡   
//所以要进行信号捕捉

//5.1.信号捕捉的--回调函数
void callback(int num)
{
    printf("捕捉的信号：%d\n",num);
}

int main()
{
    //1、创建时间结构体
    struct itimerval newval,oldval;
	
    //2、初始化函数的第二个参数
    //2.1、定时器第一次发出信号的时间间隔
    newval.it_value.tv_sec = 5;
    newval.it_value.tv_usec = 0;
    //2.2、定时器以后每一次发送信号的周期
    newval.it_interval.tv_sec = 2;
    newval.it_interval.tv_usec = 0;

    //5、在setitimer调用之前--注册信号捕捉
    signal(SIGALRM,callback);


    //3、调用定时器函数
    setitimer(ITIMER_REAL,&newval,&oldval);
	
    //该函数默认是不阻塞，所以执行完函数调用，还没计时完毕，就已经return了
    //4、所以要阻止程序退出
    getchar();

    return 0;
}
