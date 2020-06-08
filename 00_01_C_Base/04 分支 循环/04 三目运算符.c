#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = a > b ? a: b;

	printf("a = %d\n", a); //10
	printf("b = %d\n", b); //20
	printf("c = %d\n", c); //20

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}