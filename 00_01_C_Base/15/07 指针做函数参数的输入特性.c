#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�������ԣ��������������ڴ棬��������ʹ��

//�����������䵽ջ��

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

//�������������ڶ���

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