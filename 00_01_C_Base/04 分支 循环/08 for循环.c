#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{

	//for(��ʼ���ʽ �� �������ʽ�� ĩβѭ����) { ѭ������}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}


	//forѭ���е�3�����ݿ���ʡ�Ե� ,�ֺŲ�����ʡ��
	//int j = 0;
	//for (;;)
	//{
	//	if (j == 10)
	//	{
	//		break;
	//	}
	//	printf("%d\n", j);
	//	j++;
	//}



}

//��1 �� 100 �����֣�������ָ�λ������7 ������ 7�ı���������ʮλ������7 ����ӡ������
void test02()
{

	for (int i = 1; i <= 100; i++)
	{
		//���� 7�ı���  ��λΪ7  ���� ʮλΪ7
		if ( i % 7 == 0  || i%10 == 7 || i/ 10 ==7 )
		{
			printf("������\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}

//ѭ��Ƕ��ѭ��
void test03()
{
	//���ѭ�������� i ���ڲ�ѭ�������� j
	for (int i= 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}