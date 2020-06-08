// 03multi_pthread_server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>

//6.1.创建结构体，存储：给子线程传递的信息
struct Info 
{
    int cfd;//通信的文件描述符
    struct sockaddr_in client_addr;//建立连接的客户端信息
};
//6.2.创建结构体数组
struct Info info[1024];
//7.回调函数
void * callback(void * arg)
{
    //7.1.取出参数中的数据
    struct Info* pInfo = (struct Info*)arg;
    //子进程部分：通信
    //7.通信
    while(1)
    {    
        //7.2.接受数据部分
        char buf[24];
        int len = read(pInfo->cfd,buf,sizeof(buf));
        if(len > 0 )
        {   //客户端IP
            char clientIP[17];
            inet_ntop(AF_INET,
                      &pInfo->client_addr.sin_addr.s_addr,
                      clientIP,
                      sizeof(clientIP));
            //客户端端口
            unsigned short cliPORT = ntohs(pInfo->client_addr.sin_port);
            printf("recv data:%s,client IP:%s,Port:%d\n",buf,clientIP,cliPORT);
            //7.3.发送数据
            char msg[1024];
            sprintf(msg,"你好客户端--%s:%d\n",clientIP,cliPORT);
            write(pInfo->cfd,msg,strlen(msg)+1);
        }
        else if(len == 0)
        {
            printf("client disconnect...\n");
            break;
        }
        else
        {
            perror("read");
            break;
        }
    }
	//7.4.关闭子进程文件描述符、
	//    结构体数组的这个元素的标志位置为-1
	//        表示这个元素没被任何人使用，处于空闲状态
	//    退出子线程
    close(pInfo->cfd);
    pInfo->cfd = -1;
    //
    return NULL;
	
	//不能调用exit(0)退出子线程
    //所有的线程共同使用虚拟地址空间
    //如果调用exit，它们共同住的这个房子就被拆了
}
int main()
{
    //1.创建监听的套接字
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket");
        exit(0);
    }
    //2.绑定本地IP和端口
    struct sockaddr_in server_addr;
    
    //绑定本地IP：法1
    //本地IP：192.168.11.11
    //inet_pton(AF_INET, "192.168.237.131", &addr.sin_addr.s_addr);
    //绑定本地IP：法2(更简单)
    //IP地址写： 0, 代表自动绑定本地的IP
    //如果一台主机上有N块网卡, 有N个IP地址, 0地址代表绑定所有的IP地址
    server_addr.sin_addr.s_addr = INADDR_ANY;//INADDR_ANY==0(自动绑定本地IP)
    
    server_addr.sin_family = AF_INET;//地址族协议
    server_addr.sin_port = htons(9898);//端口
    int ret = bind(fd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(ret == -1)
    {
        perror("bind");
        exit(0);
    }
    //3.设置监听
    ret = listen(fd,128);
    if(ret == -1)
    {
        perror("listen");
        exit(0);
    }
    //6.3.初始化结构体数组
    int lenInfo= sizeof(info) / sizeof(info[0]);
    for(int i = 0;i < lenInfo;++i) 
    {
		memset(&info.client_addr,0,sizeof(struct sockaddr_in));
        info[i].cfd = -1;
    }
    while(1)
    {
        //主线程
        //
        //4.阻塞等待客户端连接，并且接受建立连接
        struct sockaddr_in client_addr;
        int len1 = sizeof(client_addr);
        printf("等待客户端连接....\n");
        int cfd = accept(fd,(struct sockaddr*)&client_addr,&len1);
        if(cfd == -1)
        {
            perror("accept");
            exit(0);
        }
        //5.1.如果连接成功，创建子线程
        pthread_t tid;
        //6.4.准备信息，初始化到数组中
        struct Info* pInfo; 
        for(int i=0;i<lenInfo;++i)
        {
            if(info[i].cfd == -1)
            {
                pInfo = &info[i];
                break;
            }
        }
        pInfo->cfd = cfd;
        memcpy(&pInfo->client_addr,&client_addr,sizeof(client_addr));
        pthread_create(&tid,NULL,callback,(void *)pInfo);
		//5.2.线程分离
		//这样主线程不负责子线程的回收
        pthread_detach(tid);
    }
    //5.3.当有的子线程都关闭后
    //关闭父进程里负责监听的文件描述符
    close(fd);
    return 0;//主线程退出
}
