#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、const修饰的变量 称为常量

//const修饰的全局常量

const int a = 10; //存放在常量区，受到常量区的保护，间接修改语法通过，运行失败

void test01()
{
	//a = 1000;  error 直接修改失败

	int * p = &a;
	*p = 1000;
	//printf("%d\n", a);
}


//const修饰的局部常量
void test02()
{
	const int b = 10; //b放在栈上，直接修改失败，间接修改成功，因此在C语言中，const修饰的局部常量称为伪常量

	//a = 1000; //error 直接修改失败

	int *p = &b;

	*p = 1000;
	printf("%d\n", b);


	//int arr[b]; // error 伪常量 不可以初始化数组
}


//字符串常量  共享的
void test03()
{
	char * p1 = "hello world";
	char * p2 = "hello world";
	char * p3 = "hello world";

	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
	printf("%d\n", &"hello world");
}

//常量只读的
void test04()
{
	char * p1 = "hello world";
	printf("%c\n", p1[0]);
	//p1[0] = 'w'; //error不可以修改的
}

int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}