#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#define  N 100

//�������ļ���д�� 100 �������  ��д��󣬶�ȡ�����������򣬽����������д�뵽��һ���ļ���

void test01()
{
	FILE * fp = fopen("�����.txt", "w");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
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
	//1�����ļ�  ����ȡ�����ݣ����뵽һ��������

	FILE * fp = fopen("�����.txt", "r");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

	//׼����Ŷ�ȡ���ݵ�����
	int arr[N] = {0};

	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d\n", &arr[i]);
	}
	fclose(fp);

	//2�������������� ��������
	bubbleSort(arr);

	//3�����ź�������� д�뵽��һ���ļ���
	fp = fopen("�����.txt", "w");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
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