#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int a = 10;
	int b = 20;

	//在C和C++中  0 代表假   非零 代表真
	printf("a==b  %d\n", a == b); //0
	printf("a!=b  %d\n", a != b); //1
	printf("a>b  %d\n", a > b);   //0
	printf("a<b  %d\n", a < b);   //1
	printf("a>=b  %d\n", a >= b); //0
	printf("a<=b  %d\n", a <= b); //1
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}