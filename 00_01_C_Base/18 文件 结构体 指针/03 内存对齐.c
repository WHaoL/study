#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#pragma pack (show)  //��ӡ�ľ��Ƕ���ģ�� Ĭ����  8

//#pragma pack (1) //�޸Ķ���ģ��  ���Ըĳ�2��n�η�

//�ڴ����ԭ��
//��һ�����Լ��㣬��0��ʼƫ��
//�ڶ������Լ��㣬Ҫ����  �������ʹ�С  �� ����ģ���� ȡС��ֵ ��������
//��������Ϻ�����������ƫ�ƣ�����ṹ��Ĵ�СҪ���䵽 �����ṹ������������ �����ģ���� ȡС��ֵ��������

typedef struct _STUDENT{
	int a;    // 0 ~ 3      // 0 ~ 3
	char b;   // 4 ~ 7      // 4 ~ 4
	double c; // 8 ~ 15     // 5 ~ 12 
	float d;  // 16~ 19     // 13 ~ 16
}Student;

void test01()
{
	printf("sizeof = %d\n", sizeof(Student)); // 24
}


//���ṹ��Ƕ�׽ṹ�� �������ƫ��
typedef struct _STUDENT2{
	char a;     // 0 ~ 7
	Student b;  // 8 ~ 31 
	double c;   //32 ~ 39
}Student2;

void test02()
{
	
	printf("sizeof = %d\n", sizeof(Student2));
}


int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}