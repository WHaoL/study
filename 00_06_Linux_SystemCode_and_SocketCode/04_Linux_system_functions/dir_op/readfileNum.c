// 读某个目录下普通文件的个数
// 需要用到递归, 想明白递归结束的条件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int get_file_num(char *curPath)
{
    int total = 0;
    DIR *dir = NULL;

    // 打开目录
    // 循环从目录中读文件
    dir = opendir(curPath);
    if (dir == NULL)
    {
        perror("opendir");
        return 0;
    }

    // 存储下一级目录(绝对路径)
    char path[1024] = {0}; //

    // 定义readdir()返回的结构体指针
    // 通过该指针，可得到文件的文件名
    struct dirent *ptr = NULL;

    while ((ptr = readdir(dir)) != NULL)
    {
        // 跳过目录. 和 目录..
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        // 是目录的话，递归读取
        if (ptr->d_type == DT_DIR)
        {
            // 拼接下一级目录(绝对路径)
            sprintf(path, "%s/%s", curPath, ptr->d_name);
            // 递归读目录
            total += get_file_num(path);
        }

        // 如果是普通文件
        if (ptr->d_type == DT_REG)
        {
            total++;
        }
    }
    closedir(dir);
    return total;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("./a.out path");
        exit(1);
    }

    int total = get_file_num(argv[1]);
    printf("%s has regfile number: %d\n", argv[1], total);
    return 0;
}
