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
	
    
    int num = 0;
	
    while (1)
    {
        char buf[1024] = {0};
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "Hello I am writer ------ %d\n", num++);
		
		//2、不停的写数据
        write(fd, buf, strlen(buf) + 1);
        sleep(1);
    }
    close(fd);
    return 0;
}

