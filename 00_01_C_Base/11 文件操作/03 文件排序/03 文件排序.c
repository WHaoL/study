#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#define  N 100

//需求：向文件中写入 100 随机数字  ，写入后，读取出来并且排序，将排序后结果在写入到另一个文件中

void test01()
{
	FILE * fp = fopen("随机数.txt", "w");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		fprintf(fp, "%d\n", rand() % 100 + 1); // 1 ~ 100
	}
	fclose(fp);
}

void bubbleSort(int * arr )
{
	for (int i = 0; i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1;j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void test02()
{
	//1、读文件  将读取的数据，放入到一个数组中

	FILE * fp = fopen("随机数.txt", "r");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

	//准备存放读取数据的数组
	int arr[N] = {0};

	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d\n", &arr[i]);
	}
	fclose(fp);

	//2、将数组中数据 进行排序
	bubbleSort(arr);

	//3、将排好序的数组 写入到另一个文件中
	fp = fopen("排序后.txt", "w");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

	for (int i = 0; i < N;i++)
	{
		fprintf(fp, "%d\n", arr[i]);
	}

	fclose(fp);

}


int main(){

	srand((unsigned int)time(NULL));
	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}