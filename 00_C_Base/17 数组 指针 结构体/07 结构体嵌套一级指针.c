#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	//姓名
	char *name;
	//年龄
	int age; 
};

struct Person ** allocateSpace()
{
	struct Person ** temp = malloc(sizeof(struct Person *) * 3);

	for (int i = 0; i < 3;i++)
	{
		//创建具体Person结构体变量 
		temp[i] = malloc(sizeof(struct Person));

		//Person的属性 name  放在堆区
		temp[i]->name = malloc(sizeof(char)* 64);

		//给姓名赋值
		sprintf(temp[i]->name, "name_%d", i + 1);

		temp[i]->age = i + 18;
	}

	return temp;
}

void printArray(struct Person ** arr, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("姓名：%s  年龄:%d\n", arr[i]->name, arr[i]->age);
	}
}

void freeSpace(struct Person ** pArray)
{
	if (pArray == NULL)
	{
		return;
	}
	for (int i = 0; i < 3;i++)
	{
		//释放人的姓名
		if (pArray[i]->name != NULL)
		{
			printf("%s被释放了\n", pArray[i]->name);
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}

		//释放人
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}


	free(pArray);
	pArray = NULL;
}

void test01()
{
	struct Person ** pArray = NULL;
	//分配内存
	pArray = allocateSpace();

	//打印数组
	printArray(pArray,3);

	//释放内存
	freeSpace(pArray);
	pArray = NULL;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}