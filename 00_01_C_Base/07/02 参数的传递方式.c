#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1��ֵ����
// ͨ��һ������ʵ�������������ֽ����ĺ���
void mySwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	printf("mySwap�е�a = %d\n", a); // 20
	printf("mySwap�е�b = %d\n", b); // 10
}

void test01()
{
	int a = 10;
	int b = 20;

	//ֵ���ݵ� �β��Ǹı䲻��ʵ�ε�
	mySwap(a, b);

	printf("test01�е�a = %d\n", a);
	printf("test01�е�b = %d\n", b); 

}


//2����ַ����
void mySwap2(int * p1 , int * p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	printf("mySwap2�е�*p1 = %d\n", *p1);
	printf("mySwap2�е�*p2 = %d\n", *p2);
}

void test02()
{
	int a = 10;
	int b = 20;
	//��ַ���ݵ��β� �����޸�ʵ��
	mySwap2(&a,&b);

	printf("test02�е�a = %d\n", a);
	printf("test02�е�b = %d\n", b);
}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}