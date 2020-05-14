#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // 打开一个文件
    int fd = open("3.txt", O_RDWR|O_CREAT, 0664);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
#if 0
    int fd1 = open("3.txt", O_RDWR|O_CREAT, 0664);
    if(fd1 == -1)
    {
        perror("open");
        return -1;
    }
#endif
    int fd1 = 6;

    // 文件描述符重定向
    int ret = dup2(fd, fd1);
    printf("dup return value: %d\n", ret);
    close(fd);
    // 写文件
    char* p = "hello, Linux";
    write(fd1, p, strlen(p));
    close(fd1);

    return 0;
}
