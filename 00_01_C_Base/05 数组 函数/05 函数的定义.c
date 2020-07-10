#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义一个函数 步骤
//1、返回值类型
//2、函数名
//3、参数列表 （形参列表）
//4、函数体语句
//5、return 表达式

//定义一个函数，实现两个int类型数据相加，并且返回相加后的结果
int add(int num1,int num2) //参数列表中的num1和num2是没有数据，只是形式上的参数，形参
{
	int sum = num1 + num2;
	return sum;
}

//函数的调用
void test01()
{
	//a、b是有具体的实际上的数据，我们称为  实参
	int a = 10;
	int b = 20;
	//函数的调用语法： 函数名（具体的参数）
	//当函数调用的时候，会将实参的数据 传递给形参
	int sum = add(a, b);
	printf("sum = %d\n", sum);

	return;
}


//如果函数的定义在函数使用的上方，那么算自动声明

//如果函数的定义在函数使用的下方，需要提前声明
//提前声明

//函数的声明，告诉编译器后面有这个函数的定义，下面如果先使用，不要报错
//函数的声明可以有多次
//函数的定义只能有一次
int getMax(int num1, int num2);
int getMax(int num1, int num2);
int getMax(int num1, int num2);
int getMax(int num1, int num2); 

void test02()
{
	int a = 10;
	int b = 20;
	int ret = getMax(a, b);
	printf("较大的值为：%d\n", ret);
}

int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}


//创建一个函数，两个整型数据比较，返回较大的值
int getMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

