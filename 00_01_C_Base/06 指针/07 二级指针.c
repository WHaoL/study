#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int  a = 10;
	int * p = &a;
	int ** pp = &p;

	printf("&a = %d\n", &a); //a�����ĵ�ַ
	printf("p = %d\n", p);   //p��ֵ  ���� a�����ĵ�ַ
	printf("*p = %d\n", *p); //a��ֵ
	printf("&p = %d\n", &p); //p�����ĵ�ַ

	printf("pp = %d\n", pp);  //pp��ֵ  ���� p�����ĵ�ַ
	printf("*pp = %d\n", *pp); //*pp�� p��ֵ   ���� a�����ĵ�ַ 
	printf("**pp = %d\n", **pp); // **pp a��ֵ

	printf("&pp = %d\n", &pp); //pp�ĵ�ַ 
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}