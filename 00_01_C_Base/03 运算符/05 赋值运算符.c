#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//��ֵ ����  ��=�ұߵ�ֵ   ����=���
	int a = 10;
	a = 100;
	int b = 20;
	b = a;
	//��ֵ    �ܹ���=��ߵ�ֵ ��Ϊ��ֵ
	//��ֵ    ֻ����=�ұߵ�ֵ ��Ϊ��ֵ


	// += 
	a = 10;
	a += 2; // a = a + 2;
	printf("a = %d\n", a);  // 12
	// -=
	a = 10;
	a -= 2; // a = a - 2;
	printf("a = %d\n", a);   //8
	// *=
	a = 10;
	a *= 2; // a = a * 2;
	printf("a = %d\n", a);  // 20
	// /=
	a = 10;
	a /= 2; // a = a / 2;
	printf("a = %d\n", a);  // 5
	// %=
	a = 10;
	a %= 2; // a = a % 2;
	printf("a = %d\n", a);  // 0
}

void test02()
{
	//ע���������+=  -= *=....��  =�ұߵı��ʽҪ����һ������
	int num = 10;
	num *= 3 + 5;  // num = num * (3 + 5)
	printf("num = %d\n", num); // 80

}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}