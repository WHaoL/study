#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int num = 0;

	//while���ж�ѭ�����������������������ִ��ѭ�������
	//while (num > 10)
	//{
	//	printf("num = %d\n", num);
	//	num++;
	//}

	//do while ��while��������  do while����ִ��һ��ѭ����Ĵ��룬Ȼ�����ж�����
	do
	{
		printf("num = %d\n", num);
		num++;
	} while (num > 10);

}

//��1000����ˮ�ɻ���  
// ˮ�ɻ���ָ����һ��3λ�����֣�ÿ��λ�����ֵ� 3�η�֮�ͻ��������ֱ���
// 153  =  1 + 125 + 27 = 153

void test02()
{
	//3λ���ı�ʾ��Χ  100 ~ 999

	//1����ӡ�����е���λ��
	int num = 100;
	do 
	{
		//printf("num = %d\n", num);
		//2����ѡ��ˮ�ɻ���

		// 1 2 3 

		int a = 0; //��λ
		int b = 0; //ʮλ
		int c = 0; //��λ

		a = num % 10;
		b = num / 10 % 10; 
		c = num / 100;

		if (a * a * a + b * b * b + c * c * c == num)
		{
			//ˮ�ɻ�����
			printf("num = %d\n", num);
		}

		num++;
	} while (num < 1000);

}

int main(){

	//test02();

	system("pause");
	return EXIT_SUCCESS;
}