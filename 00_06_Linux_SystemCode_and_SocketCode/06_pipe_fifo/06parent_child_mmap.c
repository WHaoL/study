#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    //0、touch 06test.mmap

    //1、准备磁盘文件
    int fd = open("06test.mmap", O_RDWR);
    if (-1 == fd)
    {
        perror("open");
        exit(-1);
    }

    //2、求磁盘文件大小
    int fileLength = lseek(fd, 0, SEEK_END);
    printf("file length : %d\n", fileLength);

    //3、创建内存映射区
    void *mptr = mmap(NULL, fileLength, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (MAP_FAILED == mptr)
    {
        perror("mmap");
        exit(0);
    }

    //4、创建子进程
    pid_t pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        exit(0);
    }

    // parent send data
    int num = 0;
    if (pid > 0)
    {
        char basebuf[] = "I am your father!!!";
        char buf1[1024] = {0};
        sprintf(buf1, "%s------%d\n", basebuf, num++);
        memcpy(mptr, buf1, strlen(buf1) + 1);
    }
    // chile recv data
    else if (0 == pid)
    {
        char buf2[1024] = {0};
        memcpy(buf2, mptr, strlen((char *)mptr));
        printf("%s\n", buf2);
    }

    munmap(mptr, fileLength);

    return 0;
}
