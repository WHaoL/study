#include <stdio.h>
int g_b = 1000; //普通全局变量


//全局函数

void func1()
{
	printf("func1调用了!\n");
}

//静态函数  只能在本文件中使用
static void func2()
{
	printf("func2调用了!\n");
}
