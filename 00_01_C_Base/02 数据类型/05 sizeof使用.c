#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sizeof ͳ��һ������  ����һ������ ռ�õ��ڴ�ռ��С
void test01()
{
	printf("shortռ���ڴ�ռ�Ϊ��%d\n", sizeof(short)); //2

	int a = 10;
	printf("aռ���ڴ�ռ�Ϊ: %d\n", sizeof(a)); //4
	printf("int ռ���ڴ�ռ�Ϊ: %d\n", sizeof(int)); //4

	printf("long ռ���ڴ�ռ�Ϊ: %d\n", sizeof(long)); //4

	printf("long long ռ���ڴ�ռ�Ϊ: %d\n", sizeof(long long)); // 8
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}