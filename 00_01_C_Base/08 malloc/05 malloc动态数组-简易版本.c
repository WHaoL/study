#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//设置数组中元素
void setArray(int * arr , int num)
{
	printf("请输入%d个元素的值\n", num);

	for (int i = 0; i < num;i++)
	{
		scanf("%d", &arr[i]);
	}
}

//打印输出
void printArray(int * arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test01()
{
	int n = 0; //数组元素个数
	printf("请输入数组元素个数:\n");

	scanf("%d", &n);

	//arr 是数组首元素的地址
	int * arr = malloc(sizeof(int)* n);

	if (arr == NULL)
	{
		printf("申请失败\n");
		return;
	}

	//清空数组
	memset(arr, 0, sizeof(int)* n);

	//设置数组中元素
	setArray(arr, n);

	//打印输出
	printArray(arr, n);

	//释放
	free(arr);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}