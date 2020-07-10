#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int  a = 10;
	int * p = &a;
	int ** pp = &p;

	printf("&a = %d\n", &a); //a变量的地址
	printf("p = %d\n", p);   //p的值  就是 a变量的地址
	printf("*p = %d\n", *p); //a的值
	printf("&p = %d\n", &p); //p变量的地址

	printf("pp = %d\n", pp);  //pp的值  就是 p变量的地址
	printf("*pp = %d\n", *pp); //*pp是 p的值   就是 a变量的地址 
	printf("**pp = %d\n", **pp); // **pp a的值

	printf("&pp = %d\n", &pp); //pp的地址 
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}