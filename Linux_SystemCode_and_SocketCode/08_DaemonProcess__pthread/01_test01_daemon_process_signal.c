// 1. 写一个守护进程, 每隔2s获取一次系统时间, 将这个时间写入到磁盘文件.
// 	
​// 	创建守护进程- 6步
​// 	注册信号捕捉 -> sigaction
​// 	设置定时器 -> setitimer
​// 	获取系统时间操作
​// 	写磁盘

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

//3.2、回调函数
//捕捉到定时器发出的信号之后的处理动作
void callback_writefile(int num)
{
    //4.1、获取当前时间
    time_t curtime = time(NULL);
	
   //需要将得到的总秒数，转换为本地实际
    //方式1：利用函数的返回值，自己拼接出时间
    //方式2：使用asctime函数，得到格式化好的时间
    struct tm* mytime = localtime(&curtime);
    //使用asctime函数，格式化时间结构体
    char * strtime = asctime(mytime);
	
    //得到时间字符串
    //4.2、写入到文件里面
    int fd3 = open("mytesttime.txt",O_WRONLY|O_APPEND|O_CREAT,0664);
    write(fd3,strtime,strlen(strtime));
    close(fd3);
}
int main()
{
    //1、创建守护进程
    //1.1、创建子进程
    pid_t pid = fork();
    //1.2、杀死父线程
    if(pid > 0)
    {
        //父进程
        exit(0);
    }
    //父进程已经被杀死，下面都是子进程的代码
    //1.3、将子线程提升为会话
    setsid();
    //1.4、切换工作目录
    chdir("/home/lwh");//改为当前用户的家目录
    //1.5、修改文件掩码
    umask(0002);//设置的和系统默认是一样的
    //1.6、文件重定向
    int fd2 = open("/dev/null",O_RDWR);
    dup2(fd2,0);
    dup2(fd2,1);
    dup2(fd2,2);
    
    //1.7、核心操作
    
    //3.1、注册信号捕捉(在信号发出之前)
    //因为：定时器发出的信号会杀死当前的进程/线程 
    struct sigaction mysig;
    mysig.sa_flags = 0;
    sigemptyset(&mysig.sa_mask);
    mysig.sa_handler = callback_writefile;
    sigaction(SIGALRM,&mysig,NULL);
	
    //2.1、设置定时器
    struct itimerval newtime;
    newtime.it_value.tv_sec = 5;//第一次触发的时间间隔
    newtime.it_value.tv_usec = 0;
    newtime.it_interval.tv_sec = 2;//周期性间隔
    newtime.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL,&newtime,NULL);     
    while(1)
    {   //setitimer执行完了以后，进程直接退出了
        //也就无法在后台继续运行了
        sleep(10000);
        //让进程一直睡
        //因为信号优先级很高，当捕捉到信号后
        //就会醒来去执行回调函数
        //处理完了之后，接着会去睡
        //如此往复的循环执行
    }
    return 0;

}

