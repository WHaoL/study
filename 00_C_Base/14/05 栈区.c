#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1����Ҫ���ؾֲ�������ַ
int * func()
{
	int a = 10; //�ֲ�����  ����ջ��
	return &a;
}

void test01()
{
	int * p = func();
	//����Ľ������Ҫ���Ƿ���������ڴ�
	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
}


char * getString()
{
	char str[] = "hello world";

	return str;
}

void test02()
{
	char * p = NULL;

	p = getString();
	//getString�е�str�Ѿ����ͷ��ˣ���ͨ��ָ����ʣ�Ҳ���ڷǷ�����
	printf("%s\n", p);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}