#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��ȫ�ֱ��������ǿ
int a;
int a = 10;


//2��������ǿ  C�����¿��Բ�д����ֵ���ͣ��ββ�д�������ͣ������������Բ���
getRectS( w,  h)
{
	return w * h;
}

void test01()
{
	getRectS(10, 10, 10);
}

//3������ת�������ǿ
void test02()
{
	char *  p = malloc(64);
}


//4��struct ��ǿ
//C������ �ṹ���в������к���
struct Person
{
	int age;
	//void showAge(){};
};

void test03()
{
	struct Person p1; //����Ҫ��struct �ؼ���
}

//5��bool���� �������
//bool flag = true;


//6����Ŀ�������ǿ
void test05()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	//a > b ? a : b = 100; //C���صĽ����ֵ

	*(a > b ? &a : &b) = 100;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}

//7��const��ǿ

//ȫ��const���εı���
const int m_a = 100; //���ڳ��������ܵ�����
void test06()
{
	//m_a = 200;
	//int * p = &m_a;
	//*p = 1000;

	//�ֲ�const���εı���  ����ջ��
	const int m_b = 100;
	//m_b = 200;
	int * p = &m_b;
	*p = 1000;
	printf("m_b = %d\n", m_b);

	//α����  �����Գ�ʼ������
	//int arr[m_b];
}

int main(){

	test06();

	system("pause");
	return EXIT_SUCCESS;
}