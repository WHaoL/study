// test_-DDEBUG.c
// gcc test_-DDEBUG.c -o test_-DDEBUG  -D DEBUG
#include <stdio.h>
int main()
{
    int a = 10;
#ifdef DEBUG
    printf("我是一个程序猿, 我不会爬树...\n");
#endif
    for(int i=0; i<3; ++i)
    {
        printf("hello, GCC!!!\n");
    }
    return 0;
}
