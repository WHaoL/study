#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // 打开一个文件
    int fd = open("1.txt", O_WRONLY);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
#if 0
    // 追对文件的操作属性
    // 先得到原来设置的属性
    int flag = fcntl(fd, F_GETFL); 
    // 属性添加
    flag |= O_APPEND;
    // flag = flag | O_APPEND;
    // 设置属性到文件描述符中
    fcntl(fd, F_SETFL, flag);
#endif
    // 写文件
    char* p = "你好, 世界....";
    write(fd, p, strlen(p));
    close(fd);

    return 0;
}
