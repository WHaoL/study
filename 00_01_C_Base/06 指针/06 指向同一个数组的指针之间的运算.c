#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int * p1 = arr;
	int * p2 = &arr[4]; // 数据元素5的地址 

	//两个指针变量进行相加 无意义
	//printf("%d\n", p1 + (int)p2);

	//获取两个指针变量间元素的个数(偏移量为4）
	printf("p2 - p1 = %d\n", p2 - p1);

	//两个指针变量进行相乘 无意义
	//printf("p2 * p1 = %d\n", (int)p2*(int)p1);
	//两个指针变量进行相除 无意义
	//printf("p2 / p1 = %d\n", (int)p2 / (int)p1);

	if (p1 == NULL)
	{
		printf("p1是空指针\n");
	}
	else
	{
		printf("p1不是空指针\n");
		if (p1 != p2)
		{
			printf("p1 != p2\n");
		}
		else
		{
			printf("p1 == p2\n");
		}
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}