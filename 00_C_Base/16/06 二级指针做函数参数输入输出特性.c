#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//输入特性：主调函数分配内存被调函数使用
void printArray(int ** arr, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("数组中第%d个元素的值为:%d\n", i + 1, *arr[i]);
	}
}
void test01()
{
	int ** pArray = malloc(sizeof(int *)* 5);

	//在栈上分配数据
	int a1 = 100;
	int a2 = 200;
	int a3 = 300;
	int a4 = 400;
	int a5 = 500;

	pArray[0] = &a1;
	pArray[1] = &a2;
	pArray[2] = &a3;
	pArray[3] = &a4;
	pArray[4] = &a5;

	int len = 5;

	printArray(pArray, len);

	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}

}


void test02()
{
	int * pArray[5];

	for (int i = 0; i < 5;i++)
	{

		pArray[i] = malloc(4);
		*(pArray[i]) = i + 100;
	}

	int len = sizeof(pArray) / sizeof(int*);

	//打印数组
	printArray(pArray, len);

	//释放堆区
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}

}





//输出特性
void allocateSpace(int **pp)
{
	int * p = malloc(sizeof(int)* 10);
	for (int i = 0; i < 10;i++)
	{
		p[i] = i + 100;
	}

	*pp = p;
}

void printArray2(int ** arr , int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", (*arr)[i]);
	}
}

void freeSpace(int ** p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void test03()
{
	int * p = NULL;

	allocateSpace(&p);

	printArray2(&p,10);

	//释放内存
	freeSpace(&p);

	if (p == NULL)
	{
		printf("空指针\n");
	}
	else
	{
		printf("野指针\n");
	}

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}