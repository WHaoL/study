#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void printArray(int * arr, int len)
void printArray(int arr[] ,int len)  //��ߴ���ɶ��ԣ������ַ�ʽд�������
{
	for (int i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//�������ǲ���ָ�룿���� 
void test01()
{
	//����������������������⣬����ָ��������Ԫ�ص�ָ��

	//1�������������� sizeof
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("%d\n", sizeof(arr)); //20

	//2����������ȡ��ַ
	//int **p = &arr;  ���ȼ�ָ��

	//&arr ָ��Ĳ�������������ĳ���
	printf("%d\n", &arr);
	printf("%d\n", &arr + 1);

	int * p = arr; //������������⣬����ָ����Ԫ�ص�ַ

	//������  ��ָ�볣��  int * const p   
	//arr = NULL; //ָ���ָ�� �������޸�
	arr[0] = 100; //ָ��ָ���ֵ ���Ը�

	//��ӡ����
	int len = sizeof(arr) / sizeof(int);
	printArray(arr,len);


	p = p + 3;
	//����Ԫ�ط��ʵ��±� �ɲ������Ǹ�����
	printf("%d\n", p[-1]);
	printf("%d\n", *(p-1) );
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}