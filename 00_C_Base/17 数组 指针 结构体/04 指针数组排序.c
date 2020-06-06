#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ѡ������
void selectSort(int arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int min = i; //�϶���Сֵ�±�Ϊi
		for (int j = i + 1; j < len;j++)
		{
			if (arr[min] > arr[j]) //�϶�����Сֵ�±�Ԫ�� �� j�����Ĵ�˵��j�Ǹ�С���±�
			{
				min = j;
			}
		}
		//�ж���Сֵ�±�  �ǲ���i��������ǣ�����Ԫ��
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
	//��С��������

	int len = sizeof(arr) / sizeof(int);

	//ѡ������
	selectSort(arr, len);

	//��ӡ����
	printArray(arr, len);
}



void selectSort2(char * arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //�϶����ֵ�±�
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

	//�������Ӵ�С���㷨����ѡ������

	int len = sizeof(pArray) / sizeof(char*);
	selectSort2(pArray, len);

	printArray2(pArray, len);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}