#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//参数1 代表数组第一个元素的地址   参数2 数组元素的个数
//数组名做函数参数传递的时候，形参中的数组名退化为指针，指向数组中第一个元素的地址
void printArray(int * arr,int num)
{
	//printf("printArray sizeof arr = %d\n", sizeof(arr)); //4
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
		//printf("%d ", *(arr + i));
	}
	printf("\n");
}

void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	int num = sizeof(arr) / sizeof(int);
	//printf("sizeof arr = %d\n", sizeof(arr));  // 20
	printArray(arr, num);

}


void setArray(int * arr ,int num)
{
	for (int i = 0; i < num;i++)
	{
		scanf("%d", &arr[i]);
		//scanf("%d", arr + i);
	}
}

void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(arr) / sizeof(int);
	printf("请重新给5个元素赋值\n");
	setArray(arr, num);
	printArray(arr, num);
}


//找数组最大值的函数
int getArrayMax(int * arr, int num)
{
	int max = 0;//第一个数认定为最大值，记录第一个数据的下标
	for (int i = 1; i < num; i++)
	{
		if (arr[max] < arr[i])
		{
			//更新最大值下标
			max = i;
		}
	}
	return arr[max];
}

void test03()
{
	int arr[5] = { 0 };
	int num = sizeof(arr) / sizeof(int);
	printf("请重新给5个元素赋值\n");
	setArray(arr, num);
	printf("赋值后的结果为:\n");
	printArray(arr, num);
	//在数组中找到最大值
	int max = getArrayMax(arr, num);
	printf("数组中最大值为:%d\n", max);
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}