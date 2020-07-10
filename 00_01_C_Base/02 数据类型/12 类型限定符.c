#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、extern
void test01()
{
	//声明变量用，声明时候并没有给变量分配内存空间
	extern int a;
	printf("a = %d\n", a);
}
int  a = 10;

//2、const
void test02()
{
	//用const限定变量的时候，让变量变为只读状态，常量
	const int b = 10;

	printf("b = %d\n", b);
	
	//b = 1000;  error  b是常量
}

//3、register 寄存器变量
void test03()
{
	register int num = 10;
	printf("%d\n", num);
	
	//printf("%d\n", &num); //error 寄存器变量 不可以取地址
}

//4、volatile 防止编译器优化代码
void test04()
{
	volatile int num = 10;
	num = 100;
	num = 100;
	num = 120;
	num = 130;
	num = -10;
	num = 100;

	//编译器有可能优化成  只有一行的 num = 100;的代码
	//为了防止这样的优化，可以加volatile
	
	//如果有些数据需要实时的检查，那么可以加上关键字
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}