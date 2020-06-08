// 02multi_process_server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

//7.2.回调函数--回收子进程资源
void callback(int num)
{
    while(1)
    {
        pid_t pid  = waitpid(-1,NULL,WNOHANG);
        if(pid == 0 || pid == -1)
        {
            //还有子进程 或者 回收完毕
            break;
        }
        printf("回收的子进程PID：%d\n",num);
    }
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
    server_addr.sin_family = AF_INET;//地址族协议
    server_addr.sin_port = htons(9999);//端口
    inet_pton(fd,"192.168.184.132",&server_addr.sin_addr.s_addr);
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
    //7.1.注册信号捕捉
    //当子进程退出时，会给父进程发送SIGCHLD信号
    //我们捕捉，然后回收子进程资源
    struct sigaction act;
    act.sa_flags = 0; // 使用自定义回调函数
    sigemptyset(&act.sa_mask);
    act.sa_handler = callback;//自定义的回调函数 
    sigaction(SIGCHLD,&act,NULL);
    
    while(1)
    {
        //主进程：等待客户端连接，并进行处理
        //4.阻塞等待客户端连接，并且接受建立连接
        struct sockaddr_in client_addr;
        int len1 = sizeof(client_addr);

        printf("等待客户端连接....\n");

        int cfd = accept(fd,(struct sockaddr*)&client_addr,&len1);
        if(cfd == -1)
        {
            if(errno == EINTR)
            {//如果是信号导致的函数调用失败，就continue
             // 即：重新调用accept函数
                continue;
            }
            perror("accept");
            exit(0);
        }
        //5.如果连接成功，创建子进程
        pid_t pid = fork();
        if(pid == 0)
        {
            //子进程部分：通信
            //6.通信
            while(1)
            {//6.1从父进程复制过来的父进程用来监听连接请求的文件描述符，没用处
                close(fd);
                //6.2.接收数据部分
                char buf[24];
                int len = read(cfd,buf,sizeof(buf));
                if(len > 0 )
                {   //客户端IP
                    char clientIP[17];
                    inet_ntop(AF_INET,
                             &client_addr.sin_addr.s_addr,
                             clientIP,
                             sizeof(clientIP));
                    //客户端端口
                    unsigned short cliPORT = ntohs(client_addr.sin_port);
                    printf("recv data:%s,client IP:%s,Port:%d\n",buf,clientIP,cliPORT);
                    //6.3.发送数据
                    char msg[1024];
                    sprintf(msg,"你好客户端--%s:%d\n",clientIP,cliPORT);
                    write(cfd,msg,strlen(msg)+1);
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
            close(cfd);//关闭子进程文件描述符
            exit(0);//子进程退出
        }
        else if(pid > 0)
        {
            //父进程代码
            //父进程只负责监听连接请求，不负责通信
            //父进程中用来通信的文件描述符--没用处
            //所以：关闭父进程里的cfd
            close(cfd);
            
        }
    }
    //当有的子进程都关闭后，就关闭父进程监听的文件描述符
    close(fd);
    return 0;
}

