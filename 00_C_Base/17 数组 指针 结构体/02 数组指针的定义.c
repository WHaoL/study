#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ָ��Ķ���

//1���ȶ������������ͣ���ͨ���������Ͷ���ָ��
void test01()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	typedef int(ARRAY_TYPE)[5]; //ARRAY_TYPE��һ���������ͣ����5��intԪ�ص����������
	ARRAY_TYPE * arrP = &arr; //arrP��������ָ��

	// *arrP �� arr

	for (int i = 0; i < 5;i++)
	{
		//printf("%d\n", (*arrP)[i]);
		printf("%d\n", *((*arrP)+i) );
	}
}

//2���ȶ�������ָ������ͣ���ͨ������ָ������ ��������ָ�����
void test02()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	typedef int(*ARRAY_TYPE)[5];

	// *arrP �� arr
	ARRAY_TYPE arrP = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrP)[i]);
		printf("%d\n", *((*arrP) + i));
	}
}

//3��ֱ�Ӷ�������ָ�����
void test03()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int(*p)[5]  = &arr;

	//*p -> arr
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*p)[i]);
	}
}

int main(){

	test03();
	
	system("pause");
	return EXIT_SUCCESS;
}