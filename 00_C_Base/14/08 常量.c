#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��const���εı��� ��Ϊ����

//const���ε�ȫ�ֳ���

const int a = 10; //����ڳ��������ܵ��������ı���������޸��﷨ͨ��������ʧ��

void test01()
{
	//a = 1000;  error ֱ���޸�ʧ��

	int * p = &a;
	*p = 1000;
	//printf("%d\n", a);
}


//const���εľֲ�����
void test02()
{
	const int b = 10; //b����ջ�ϣ�ֱ���޸�ʧ�ܣ�����޸ĳɹ��������C�����У�const���εľֲ�������Ϊα����

	//a = 1000; //error ֱ���޸�ʧ��

	int *p = &b;

	*p = 1000;
	printf("%d\n", b);


	//int arr[b]; // error α���� �����Գ�ʼ������
}


//�ַ�������  �����
void test03()
{
	char * p1 = "hello world";
	char * p2 = "hello world";
	char * p3 = "hello world";

	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
	printf("%d\n", &"hello world");
}

//����ֻ����
void test04()
{
	char * p1 = "hello world";
	printf("%c\n", p1[0]);
	//p1[0] = 'w'; //error�������޸ĵ�
}

int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}