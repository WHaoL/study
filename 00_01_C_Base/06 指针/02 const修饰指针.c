#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��const ���ε� *      ��Ϊ����ָ��
void test01()
{
	int a = 10;
	const int  *p = &a; //*pֻ��  p�ɶ���д   �ȼ��� int const  *p = &a;
	
	//*p = 100; //error ָ��ָ���ֵ �������޸�

	int b = 20;
	p = &b;  //success ָ���ָ������޸�
}

//2��const ���ε� p   ��Ϊָ�볣��
void test02()
{
	int a = 10;
	int *  const p = &a;//*p�ɶ���д   pֻ��

	*p = 20; //success  ָ��ָ���ֵ �����޸ĵ�

	int b = 20;

	//p = &b; // error  ָ���ָ�򲻿����޸�

}


//3��const ���� * �� p
void test03()
{
	int a = 10;
	const int * const p = &a; //�ȼ��� int const * const p = &a;

	//*p = 100;  error ָ��ָ���ֵ�����Ը�

	int b = 20;
	//p = &b;  errorָ���ָ�򲻿��Ը�

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}