#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//whileѭ��
void test01()
{
	int num = 0;

	while (num < 10)
	{
		printf("num = %d\n", num);
		//ѭ���������һ���˳�������,����������ѭ��
		num++;
	}
}


// ��������Ϸ
// ��ϵͳ����һ������� ��1~100֮�� , ���ǽ��в²⣬
// ����´���ʾ�²�����ǹ�С������¶ԣ���ϲ�û���������Ϸ

void test02()
{
	//�������������  ����ϵͳ�ṩ��ʱ���õ���ͬ���
	// ��1970 1 �� 1��  0:00:00 ��ʼ ��ĿǰΪֹ��ʱ�������

	srand((unsigned int)time(NULL));//��ȡ��ǰϵͳʱ��


	//int i = 0;
	//while (i<10)
	//{
	//	int num = rand() % 100 + 1; //  0 +1  ~ 99  + 1   ->  1 ~ 100
	//	printf("%d\n", num);
	//	i++;
	//}

	//1�����������
	int num = rand() % 100 + 1;

	//2����ҽ��в²�

	int val = 0; //�����������²�����

	while (1)
	{
		//���������һ������
		scanf("%d", &val);

		//3���ж���ҵĲ²�

		if (val > num) //�û��������ִ���
		{
			printf("����������ֹ���\n");
		}
		else if (val < num)
		{
			printf("����������ֹ�С\n");
		}
		else
		{
			//�¶���
			printf("��ϲ���¶��ˣ�\n");
			//�˳�ѭ�� ����break�����˳���ǰѭ��
			break;
		}
	}
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}