#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ָ��ļ�Ӹ�ֵ
//1����������
//2��������ϵ
//3��ͨ��*�����ڴ�
void test01()
{
	int a = 10;
	int  * p = NULL;

	p = &a;

	*p = 100;

	printf("a = %d\n", a);
}

void changeValue(int * p) // int * p = &a
{
	*p = 200;
}

void test02()
{
	int a = 10;
	changeValue(&a);
	printf("a = %d\n", a);

	printf("%d\n", &a);
}



int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}