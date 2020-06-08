#include <stdio.h>
#include <ctype.h>
//从标准输入读取内容，转化为大写再输出
int main()
{
    int c = getchar();
    while(c!=EOF)
    {
        putchar(toupper(c));
        c=getchar();
    }
    return 0;
}
