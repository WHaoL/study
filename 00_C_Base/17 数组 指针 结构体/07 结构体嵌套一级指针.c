#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	//����
	char *name;
	//����
	int age; 
};

struct Person ** allocateSpace()
{
	struct Person ** temp = malloc(sizeof(struct Person *) * 3);

	for (int i = 0; i < 3;i++)
	{
		//��������Person�ṹ����� 
		temp[i] = malloc(sizeof(struct Person));

		//Person������ name  ���ڶ���
		temp[i]->name = malloc(sizeof(char)* 64);

		//��������ֵ
		sprintf(temp[i]->name, "name_%d", i + 1);

		temp[i]->age = i + 18;
	}

	return temp;
}

void printArray(struct Person ** arr, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("������%s  ����:%d\n", arr[i]->name, arr[i]->age);
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
		//�ͷ��˵�����
		if (pArray[i]->name != NULL)
		{
			printf("%s���ͷ���\n", pArray[i]->name);
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}

		//�ͷ���
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
	//�����ڴ�
	pArray = allocateSpace();

	//��ӡ����
	printArray(pArray,3);

	//�ͷ��ڴ�
	freeSpace(pArray);
	pArray = NULL;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}