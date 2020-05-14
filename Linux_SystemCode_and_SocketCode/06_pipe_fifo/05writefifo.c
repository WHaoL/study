#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    //1、打开管道文件
    int fd = open("05test.fifo",O_WRONLY);
    //2、不停的读数据
    int num=0;
    while(1)
    {
        char buf[1024];
        sprintf(buf,"hello world ----%d\n",num++);
        write(fd,buf,strlen(buf)+1);
        sleep(1);
    }
    close(fd);
    return 0;
}

