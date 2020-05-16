#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int g_a = 1000;

int* getAddress()
{
	return &g_a;
}

void test01()
{
	int * p = getAddress(); //int * p = &g_a;

	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);

	*p = 2000;

	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);
}

int main(){

	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}