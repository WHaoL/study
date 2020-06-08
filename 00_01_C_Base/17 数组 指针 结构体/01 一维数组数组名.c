#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void printArray(int * arr, int len)
void printArray(int arr[] ,int len)  //提高代码可读性，用这种方式写数组参数
{
	for (int i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//数组名是不是指针？？？ 
void test01()
{
	//数组名除了两种特殊情况外，都是指向数组首元素的指针

	//1、对数组名进行 sizeof
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("%d\n", sizeof(arr)); //20

	//2、对数组名取地址
	//int **p = &arr;  不等价指针

	//&arr 指针的步长是整个数组的长度
	printf("%d\n", &arr);
	printf("%d\n", &arr + 1);

	int * p = arr; //除了特殊情况外，都是指向首元素地址

	//数组名  是指针常量  int * const p   
	//arr = NULL; //指针的指向 不可以修改
	arr[0] = 100; //指针指向的值 可以改

	//打印数组
	int len = sizeof(arr) / sizeof(int);
	printArray(arr,len);


	p = p + 3;
	//数组元素访问的下标 可不可以是负数？
	printf("%d\n", p[-1]);
	printf("%d\n", *(p-1) );
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}