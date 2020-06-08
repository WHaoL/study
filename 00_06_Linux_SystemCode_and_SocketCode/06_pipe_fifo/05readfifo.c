#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    //1、创建有名管道
    int ret = mkfifo("05test.fifo",0777);
    if(ret == -1)
    {
        perror("mkfifo");
    }
    //2、打开管道文件
    int fd = open("05test.fifo",O_RDONLY);
    //3、不停的读数据
    while(1)
    {
        char buf[1024];
        int ret = read(fd,buf,sizeof(buf));
        printf("recv data：%s\n",buf);
        if(ret == 0)
        {
			printf("写端关闭，数据已经全部读出\n");

            break;
        }
    }
    close(fd);
    return 0;
}

