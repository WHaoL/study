#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//break  �� 
// 1  switch ��������֧�� 
// 2  ѭ�����˳�����ѭ���� 
// 3  Ƕ��ѭ�����˳� �ڲ�ѭ��
void test01()
{
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			printf("* ");
		}
		printf("\n");
	}
}


//continue
void test02()
{
	//��������ʣ��Ĵ��룬ִ����һ�ε�ѭ��

	for (int i = 0; i < 100;i++)
	{
		if (i % 2 == 0)
		{	
			continue; //�����˳�ѭ������break ���˳�ѭ��
		}
		printf("i = %d\n", i);
	}
}

//goto  ��������ת���
//���������ó�����ң���������
void test03()
{
	printf("1\n");
	printf("2\n");

	goto FALG;

	printf("3\n");
	printf("4\n");

FALG:
	printf("5\n");
	printf("6\n");
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}