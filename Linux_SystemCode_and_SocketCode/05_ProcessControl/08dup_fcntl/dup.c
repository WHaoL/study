#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // 打开一个文件
    int fd = open("1.txt", O_RDWR|O_CREAT, 0664);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    // 复制文件描述符
    int fd1 = dup(fd);
    close(fd);
    // 写文件
    char* p = "hello, Linux";
    write(fd1, p, strlen(p));
    close(fd1);

    return 0;
}
