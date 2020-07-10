#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//不同类型的指针的区别
//1、指针变量的跨度不同（+1之后跳跃的字节数不同）
void test01()
{
	char * p1 = NULL;
	printf("p1 = %d\n", p1);
	printf("p1 + 1 = %d\n", p1+1);

	int * p2 = NULL;
	printf("p2 = %d\n", p2);
	printf("p2 + 1 = %d\n", p2 + 1);

	double * p3 = NULL;
	printf("p3 = %d\n", p3);
	printf("p3 + 1 = %d\n", p3 + 1);
}

//2、解引用的时候，取出的字节数不同
void test02()
{
	int num = 0x01020304;

	int * p = &num;

	printf("*p = %#x\n", *p);

	short * p1 = &num;
	printf("*p1 = %#x\n", *p1);


	char *p2 = &num;
	printf("*p2 = %#x\n", *p2);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}