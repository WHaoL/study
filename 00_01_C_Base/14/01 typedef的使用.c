#define _CRT_SECURE_NO_WARNINGS  //��ֹ C4996���� 
#include<stdio.h>  //��׼�������ͷ�ļ�   std  ��׼  i  input  ����  o output  ���
#include<string.h>  //�ַ���������  strcpy  strcmp  strstr 
#include<stdlib.h>  //��׼��ͷ�ļ�   malloc   free


//1��typedefʹ��
//��;�������������
//���Լ�struct �ؼ���
//struct Person
//{
//	char name[64]; //����
//	int age; //����
//};
//typedef struct Person  MyPerson;


typedef struct Person
{
	char name[64]; //����
	int age; //����
}MyPerson;


void test01()
{
	struct Person p1;

	MyPerson p2;
}


//2��typedef������������
void test02()
{
	//char  *p1, p2;
	//�﷨ typedef  ԭ��  ����
	typedef char * PCHAR;

	PCHAR p1, p2;


	char *p3, *p4;
}


//3�������ֲ��
typedef int MYINT;
void test03()
{

	MYINT a = 100;


	MYINT b = 100;
}


//�������� main����
int main(){





	system("pause"); //���� 
	return EXIT_SUCCESS; //���������˳�ֵ
}