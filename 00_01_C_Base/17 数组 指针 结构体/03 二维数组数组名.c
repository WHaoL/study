#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int arr[3][3] = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	//int arr2[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//int arr3[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//1、sizeof统计整个数组长度
	printf("sizeof = %d\n", sizeof(arr));

	//2、二维数组名称取地址  二维数组数组指针
	int(*p)[3][3] = &arr;

	//除了上述两种特殊情况外，二维数组的数组名是 指向第一个一维数组的指针
	int(*pArr)[3] = arr;

	printf("%d\n", arr[1][2]); //给人看

	printf("%d\n",  *(*(pArr + 1) + 2)); //给机器看
}


//二维数组做函数参数
//void printArray(int(*pArr)[3], int row, int col)
//void printArray(int pArr[][3], int row, int col)
void printArray(int pArr[3][3], int row,int col)  //可读性最高
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", pArr[i][j]);

			//printf("%d ", *(*(pArr + i) + j) );
		}
		printf("\n");
	}
}

void test02()
{
	int arr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	
	int row = sizeof(arr) / sizeof(arr[0]);
	printf("row = %d\n", row);
	int col = sizeof(arr[0]) / sizeof(int);
	printf("col = %d\n", col);

	printArray(arr, row, col);

}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}