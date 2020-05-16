#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、全局变量
//声明时候写在函数体外部
//在本文件或其他文件中都可以使用

void test01()
{
	extern int g_a; //告诉编译器g_a在别的文件中，下面使用时候不要报错
	printf("g_a = %d\n", g_a);

}

//2、静态变量  只能在本文件中使用，内部链接属性
void test02()
{
	//局部静态变量
	static int s_b = 1000; //只会被初始化一次
	//extern int s_a;   
	//printf("s_a = %d\n", s_a);  error 静态变量 只能在本文件中使用
}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}