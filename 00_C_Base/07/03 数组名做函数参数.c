#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����1 ���������һ��Ԫ�صĵ�ַ   ����2 ����Ԫ�صĸ���
//�������������������ݵ�ʱ���β��е��������˻�Ϊָ�룬ָ�������е�һ��Ԫ�صĵ�ַ
void printArray(int * arr,int num)
{
	//printf("printArray sizeof arr = %d\n", sizeof(arr)); //4
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
		//printf("%d ", *(arr + i));
	}
	printf("\n");
}

void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	int num = sizeof(arr) / sizeof(int);
	//printf("sizeof arr = %d\n", sizeof(arr));  // 20
	printArray(arr, num);

}


void setArray(int * arr ,int num)
{
	for (int i = 0; i < num;i++)
	{
		scanf("%d", &arr[i]);
		//scanf("%d", arr + i);
	}
}

void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(arr) / sizeof(int);
	printf("�����¸�5��Ԫ�ظ�ֵ\n");
	setArray(arr, num);
	printArray(arr, num);
}


//���������ֵ�ĺ���
int getArrayMax(int * arr, int num)
{
	int max = 0;//��һ�����϶�Ϊ���ֵ����¼��һ�����ݵ��±�
	for (int i = 1; i < num; i++)
	{
		if (arr[max] < arr[i])
		{
			//�������ֵ�±�
			max = i;
		}
	}
	return arr[max];
}

void test03()
{
	int arr[5] = { 0 };
	int num = sizeof(arr) / sizeof(int);
	printf("�����¸�5��Ԫ�ظ�ֵ\n");
	setArray(arr, num);
	printf("��ֵ��Ľ��Ϊ:\n");
	printArray(arr, num);
	//���������ҵ����ֵ
	int max = getArrayMax(arr, num);
	printf("���������ֵΪ:%d\n", max);
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}