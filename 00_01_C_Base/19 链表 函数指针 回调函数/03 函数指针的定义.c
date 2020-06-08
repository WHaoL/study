#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//函数指针定义方式

//1、先定义出函数的类型，再通过函数类型定义函数指针

void func(int a, char b)
{
	printf("hello world\n");
}

void test01()
{
	typedef void(FUNC_TYPE)(int, char); //FUNC_TYPE也是数据类型，代表函数的返回值是void，参数是（int,char）

	FUNC_TYPE * funcP = func;

	funcP(10,'a');
}

//2、先定义出函数指针的类型，再通过函数指针类型，定义函数指针变量
void test02()
{
	typedef void(*FUNC_TYPE)(int, char);

	FUNC_TYPE funcP = func;

	funcP(20, 'b');
}

//3、直接定义函数指针变量
void test03()
{
	void(*p)(int, char)  = func;

	p(10, 'x');
}

//4、函数指针  和  指针函数 区别？
//函数指针 是一个指针 ，指向的是一个函数入口
//指针函数 是一个函数 ，这个函数的返回值类型是一个指针

//常量指针  指针常量  数组指针  指针数组  函数指针 指针函数


//函数指针数组

void func1()
{
	printf("func1被调用了\n");
}
void func2()
{
	printf("func2被调用了\n");
}
void func3()
{
	printf("func3被调用了\n");
}

void test04()
{
	//函数指针数组定义
	void(*func_arr[3])();

	func_arr[0] = func1;
	func_arr[1] = func2;
	func_arr[2] = func3;

	for (int i = 0; i < 3;i++)
	{
		func_arr[i]();
	}

}



int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}