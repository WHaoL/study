#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//变量  
	//给内存空间起名 方便我们去操作这块内存
	//变量 在程序运行期间 是可以改变的
	int a = 10;
	printf("a = %d\n",a);

	a = 20;
	printf("a = %d\n", a);
}

void test02()
{
	//变量的定义 定义的同时给变量一个初始值
	int a = 100;
	printf("a = %d\n", a);

	
	int b = 0; //定义一个变量，未初始化，结果未知
	//int b; //error 没有初始化 ，vs不可以运行  gcc可以 结果未知
	printf("b = %d\n", b);

	//建议！！！在定义变量的同时 给变量一个初始值  默认给0
}

void test03()
{
	//变量的声明
	//如果变量的定义在变量使用的前面，属于自动声明


	//如果变量的定义在变量使用的后面，需要显示声明，加入一个关键字 extern
	extern int g_c;//告诉编译器  有个g_c的变量存在，在后面可以找到，如果提前使用了，先不要报错
	printf("g_c = %d\n", g_c);
}

int g_c = 1000;

int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}