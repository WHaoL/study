#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��ջ����������
void test01()
{
	int a = 10;   // ջ��    �ߵ�ַ
	int b = 10;
	int c = 10;
	int d = 10;   // ջ��    �׵�ַ

	printf("a�ĵ�ַΪ:%d\n", &a);
	printf("b�ĵ�ַΪ:%d\n", &b);
	printf("c�ĵ�ַΪ:%d\n", &c);
	printf("d�ĵ�ַΪ:%d\n", &d);
}

//2���ڴ�洢��ʽ
void test02()
{
	int a =  0x11223344;

	char * p = &a;

	printf("%x\n", *p);    //    44  ��λ�ֽ�����  �׵�ַ

	printf("%x\n", *(p+1));//    33  ��λ�ֽ�����  �ߵ�ַ

	printf("%x\n", *(p + 2));

	printf("%x\n", *(p + 3));
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}