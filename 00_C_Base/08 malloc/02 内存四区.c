#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//全局变量   放在全局区
int g_a = 10;
int g_b = 20;

//全局常量
const int c_g_a = 100;
const int c_g_b = 100;

void test01()
{
	//局部变量  放在栈区
	int a = 10;
	int b = 20;

	printf("局部变量a的地址为%d\n", &a);
	printf("局部变量b的地址为%d\n", &b);

	printf("全局变量g_a的地址为%d\n", &g_a);
	printf("全局变量g_b的地址为%d\n", &g_b);


	//静态变量  放在全局区
	static int s_a = 10;
	static int s_b = 20;
	printf("静态局部变量s_a的地址为%d\n", &s_a);
	printf("静态局部变量s_b的地址为%d\n", &s_b);

	//常量  放在全局区
	printf("字符串常量的地址为%d\n", &"hello world");
	printf("字符串常量的地址为%d\n", &"hello C");

	//全局常量   放在全局区
	printf("全局常量c_g_a的地址为%d\n", &c_g_a);
	printf("全局常量c_g_b的地址为%d\n", &c_g_b);


	char * ch = malloc(4); //malloc返回的就是申请内存空间的首地址
	printf("堆区数据ch的地址为%d\n", ch);

}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}