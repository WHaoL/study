#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
    //1、准备磁盘文件
    int fd = open("06test.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(0);
    }

    //2、求磁盘文件大小
    int length =  lseek(fd,0,SEEK_END);
    //3、创建内存映射区
    void * ptr = mmap(NULL,length,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(0);
    }
    //4、创建子进程
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(0);
    }
    int num = 0;
    if(pid > 0 )
    {
        //父进程，写数据
        char * pt = "你是我儿子吗，我是爹！！！";
        char buf1[1024] = {0};
        sprintf(buf1,"%s-----%d\n",pt,num++);
        memcpy(ptr,buf1,strlen(buf1)+1);
    }
    else if(pid == 0)
    {
        //子进程，读数据
        char buf2[1024] = {0};
        memcpy(buf2,ptr,strlen((char *)ptr));
        printf("%s\n",buf2);
       // printf("%s\n",(char *)ptr);
        
    }
    //5、释放内存映射区
    munmap(ptr,length);

    return 0;
}

