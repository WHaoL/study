#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//����  
	//���ڴ�ռ����� ��������ȥ��������ڴ�
	//���� �ڳ��������ڼ� �ǿ��Ըı��
	int a = 10;
	printf("a = %d\n",a);

	a = 20;
	printf("a = %d\n", a);
}

void test02()
{
	//�����Ķ��� �����ͬʱ������һ����ʼֵ
	int a = 100;
	printf("a = %d\n", a);

	
	int b = 0; //����һ��������δ��ʼ�������δ֪
	//int b; //error û�г�ʼ�� ��vs����������  gcc���� ���δ֪
	printf("b = %d\n", b);

	//���飡�����ڶ��������ͬʱ ������һ����ʼֵ  Ĭ�ϸ�0
}

void test03()
{
	//����������
	//��������Ķ����ڱ���ʹ�õ�ǰ�棬�����Զ�����


	//��������Ķ����ڱ���ʹ�õĺ��棬��Ҫ��ʾ����������һ���ؼ��� extern
	extern int g_c;//���߱�����  �и�g_c�ı������ڣ��ں�������ҵ��������ǰʹ���ˣ��Ȳ�Ҫ����
	printf("g_c = %d\n", g_c);
}

int g_c = 1000;

int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}