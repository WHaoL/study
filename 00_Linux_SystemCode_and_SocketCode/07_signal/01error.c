#include <stdio.h>
#include <string.h>

int main()
{
   char * buf;//指针没有指向一块有效的内存
   strcpy(buf,"hello world");//内存越界，会段错误
   return 0;
}

