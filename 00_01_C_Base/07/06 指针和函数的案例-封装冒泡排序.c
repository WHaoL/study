#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArray(int * arr,int num)
{
	for (int i = 0; i < num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


//冒泡排序  升序
void bubbleSort(int * arr,int num)
{
	for (int i = 0; i < num - 1;i++)
	{
		for (int j = 0; j < num - i - 1;j++)
		{
			//如果j > j+1 交换元素
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void test01()
{
	//1、创建数组
	int arr[] = { 1, 4, 3, 5, 2, 7, 6, 8 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("排序前打印\n");
	//2、打印输出
	printArray(arr, num);

	//3、冒泡排序
	printf("排序后打印\n");
	bubbleSort(arr,num);
	printArray(arr, num);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}