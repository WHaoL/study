#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int * p1 = arr;
	int * p2 = &arr[4]; // ����Ԫ��5�ĵ�ַ 

	//����ָ������������ ������
	//printf("%d\n", p1 + (int)p2);

	//��ȡ����ָ�������Ԫ�صĸ���(ƫ����Ϊ4��
	printf("p2 - p1 = %d\n", p2 - p1);

	//����ָ������������ ������
	//printf("p2 * p1 = %d\n", (int)p2*(int)p1);
	//����ָ������������ ������
	//printf("p2 / p1 = %d\n", (int)p2 / (int)p1);

	if (p1 == NULL)
	{
		printf("p1�ǿ�ָ��\n");
	}
	else
	{
		printf("p1���ǿ�ָ��\n");
		if (p1 != p2)
		{
			printf("p1 != p2\n");
		}
		else
		{
			printf("p1 == p2\n");
		}
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}