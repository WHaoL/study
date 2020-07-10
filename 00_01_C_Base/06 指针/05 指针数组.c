#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int* arr[5]; //指针数组 ，一共5个元素，每个元素都是int*

	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	int num4 = 40;
	int num5 = 50;

	arr[0] = &num1;
	arr[1] = &num2;
	arr[2] = &num3;
	arr[3] = &num4;
	arr[4] = &num5;

	int n = sizeof(arr) / sizeof(int *);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", *arr[i]);
	}
}

void test02()
{
	char *arr[4] = { "aaa", "bbb", "ccc", "ddd" };

	int n = sizeof(arr) / sizeof(char *);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", arr[i]);
	}
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}