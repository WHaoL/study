#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、不要返回局部变量地址
int * func()
{
	int a = 10; //局部变量  放在栈区
	return &a;
}

void test01()
{
	int * p = func();
	//下面的结果不重要，非法操作这块内存
	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
}


char * getString()
{
	char str[] = "hello world";

	return str;
}

void test02()
{
	char * p = NULL;

	p = getString();
	//getString中的str已经被释放了，在通过指针访问，也属于非法访问
	printf("%s\n", p);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}