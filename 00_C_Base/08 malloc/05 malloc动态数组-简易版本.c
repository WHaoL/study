#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����������Ԫ��
void setArray(int * arr , int num)
{
	printf("������%d��Ԫ�ص�ֵ\n", num);

	for (int i = 0; i < num;i++)
	{
		scanf("%d", &arr[i]);
	}
}

//��ӡ���
void printArray(int * arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test01()
{
	int n = 0; //����Ԫ�ظ���
	printf("����������Ԫ�ظ���:\n");

	scanf("%d", &n);

	//arr ��������Ԫ�صĵ�ַ
	int * arr = malloc(sizeof(int)* n);

	if (arr == NULL)
	{
		printf("����ʧ��\n");
		return;
	}

	//�������
	memset(arr, 0, sizeof(int)* n);

	//����������Ԫ��
	setArray(arr, n);

	//��ӡ���
	printArray(arr, n);

	//�ͷ�
	free(arr);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}