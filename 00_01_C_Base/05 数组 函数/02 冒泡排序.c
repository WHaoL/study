#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int arr[] = { 1, 2, 6, 10, 5, 4, 3, 7, 9, 8 };

	//���ѭ��
	for (int i = 0; i < 10 - 1; i++)
	{
		//�ڲ�ѭ��
		for (int j = 0; j < 10 - i - 1; j++)
		{
			// �����һ������ �ȵڶ������ִ�  ��������
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}