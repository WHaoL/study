#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1 3 5 2 4 
//���ú�
//4 2 5 3 1 

void test01()
{
	int arr[6] = { 1,3,5,2,4,6 };

	printf("����ǰ�ı������Ϊ:\n");
	for (int i = 0; i <sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//����
	int start = 0; //��ʼ�����±�
	int end = sizeof(arr) / sizeof(int)-1; //���һ��Ԫ�ص��±�

	while (start<end)
	{
		//������ʱ����
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		//�±����
		start++;
		end--;
	}
	printf("���ú�ı������Ϊ:\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
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