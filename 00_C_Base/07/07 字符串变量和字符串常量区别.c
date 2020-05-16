#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//字符串常量
void test01()
{
	char * str = "hello world";

	printf("%c\n",str[0]);// h
	printf("%c\n", *str); // h

	//*str = 'w'; error
}

//字符串变量
void test02()
{
	char str[] = "hello world";

	printf("%c\n", str[1]);  // e
	printf("%c\n", *(str+1));// e

	str[1] = 'w';

	printf("%s\n", str);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}