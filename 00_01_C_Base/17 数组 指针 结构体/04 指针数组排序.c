#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//选择排序
void selectSort(int arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int min = i; //认定最小值下标为i
		for (int j = i + 1; j < len;j++)
		{
			if (arr[min] > arr[j]) //认定的最小值下标元素 比 j遍历的大，说明j是更小的下标
			{
				min = j;
			}
		}
		//判断最小值下标  是不是i，如果不是，交换元素
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void printArray(int arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test01()
{
	int arr[] = { 5, 3, 1, 2, 4 };
	//从小到大排序

	int len = sizeof(arr) / sizeof(int);

	//选择排序
	selectSort(arr, len);

	//打印数组
	printArray(arr, len);
}



void selectSort2(char * arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //认定最大值下标
		for (int j = i + 1; j < len;j++)
		{
			//if (arr[max] < arr[j])
			if (strcmp(arr[max], arr[j]) < 0)
			{
				max = j;
			}
		}
		if (max != i)
		{
			char * temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}

	}
}


void printArray2( char ** arr , int len )
{
	for (int i = 0; i < len;i++)
	{
		printf("%s\n", arr[i]);
	}
}

void test02()
{
	char * pArray[] = { "aaa", "ccc", "ddd", "bbb", "eee", "fff" };

	//排序规则从大到小，算法利用选择排序

	int len = sizeof(pArray) / sizeof(char*);
	selectSort2(pArray, len);

	printArray2(pArray, len);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}