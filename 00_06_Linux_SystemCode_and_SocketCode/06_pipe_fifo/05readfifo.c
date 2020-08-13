#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    //1、创建有名管道
	
    // 管道文件 ： fifo
    char fileName[] = "05test.fifo";
	
	//判断管道文件是否存在
    int ret = access(fileName, F_OK);

    if (0 == ret)
    {
        //文件已经存在
        //删除此文件
        if (remove(fileName) == 0)
        {
            printf("Remove %s success\n", fileName);
        }
        else
        {
            perror("remove");
            exit(-1);
        }
    }

    // 删除文件后，要创建fifo文件
    ret = mkfifo(fileName, 0777);
    if (-1 == ret)
    {
        perror("mkfifo");
        exit(-1);
    }
	
    //2、打开管道文件
    int fd = open("05test.fifo",O_RDONLY);
	
    //3、不停的读数据
    while (1)
    {
        char buf[1024] = {0};
        memset(buf, 0, sizeof(buf));
        int NUM = read(fd, buf, sizeof(buf) - 1);
        if (NUM > 0)
        {
            printf("recv data: %s\n", buf);
        }
        else if (NUM == 0)
        {
            printf("写端已经关闭\n");
            break;
        }
        else if (NUM == -1)
        {
            perror("read");
            exit(-1);
        }
    }
    close(fd);
    return 0;
}

