#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����һ������ ����
//1������ֵ����
//2��������
//3�������б� ���β��б�
//4�����������
//5��return ���ʽ

//����һ��������ʵ������int����������ӣ����ҷ�����Ӻ�Ľ��
int add(int num1,int num2) //�����б��е�num1��num2��û�����ݣ�ֻ����ʽ�ϵĲ������β�
{
	int sum = num1 + num2;
	return sum;
}

//�����ĵ���
void test01()
{
	//a��b���о����ʵ���ϵ����ݣ����ǳ�Ϊ  ʵ��
	int a = 10;
	int b = 20;
	//�����ĵ����﷨�� ������������Ĳ�����
	//���������õ�ʱ�򣬻Ὣʵ�ε����� ���ݸ��β�
	int sum = add(a, b);
	printf("sum = %d\n", sum);

	return;
}


//��������Ķ����ں���ʹ�õ��Ϸ�����ô���Զ�����

//��������Ķ����ں���ʹ�õ��·�����Ҫ��ǰ����
//��ǰ����

//���������������߱�������������������Ķ��壬���������ʹ�ã���Ҫ����
//���������������ж��
//�����Ķ���ֻ����һ��
int getMax(int num1, int num2);
int getMax(int num1, int num2);
int getMax(int num1, int num2);
int getMax(int num1, int num2); 

void test02()
{
	int a = 10;
	int b = 20;
	int ret = getMax(a, b);
	printf("�ϴ��ֵΪ��%d\n", ret);
}

int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}


//����һ�������������������ݱȽϣ����ؽϴ��ֵ
int getMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

