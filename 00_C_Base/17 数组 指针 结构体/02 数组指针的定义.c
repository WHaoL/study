#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//数组指针的定义

//1、先定义出数组的类型，再通过数组类型定义指针
void test01()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	typedef int(ARRAY_TYPE)[5]; //ARRAY_TYPE是一个数据类型，存放5个int元素的数组的类型
	ARRAY_TYPE * arrP = &arr; //arrP就是数组指针

	// *arrP 是 arr

	for (int i = 0; i < 5;i++)
	{
		//printf("%d\n", (*arrP)[i]);
		printf("%d\n", *((*arrP)+i) );
	}
}

//2、先定义数组指针的类型，再通过数组指针类型 定义数组指针变量
void test02()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	typedef int(*ARRAY_TYPE)[5];

	// *arrP 是 arr
	ARRAY_TYPE arrP = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrP)[i]);
		printf("%d\n", *((*arrP) + i));
	}
}

//3、直接定义数组指针变量
void test03()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int(*p)[5]  = &arr;

	//*p -> arr
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*p)[i]);
	}
}

int main(){

	test03();
	
	system("pause");
	return EXIT_SUCCESS;
}