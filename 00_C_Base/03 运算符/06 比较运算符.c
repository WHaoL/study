#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int a = 10;
	int b = 20;

	//��C��C++��  0 �����   ���� ������
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