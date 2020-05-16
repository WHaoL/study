#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//输入特性：主调函数分配内存，被调函数使用

//主调函数分配到栈上

void func(char * buf)
{
	strcpy(buf, "hello");
}

void test01()
{
	char buf[1024] = { 0 };

	func(buf);

	printf("%s\n", buf);
}

//主调函数分配在堆区

void printString(char * p)
{
	printf("%s\n", p);
}

void test02()
{
	char * p = malloc(sizeof(char)* 64);

	memset(p, 0, 64);

	strcpy(p, "hello world");

	printString(p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}