#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���� �� �Զ�����ת������ʽ����ת����  ǿ������ת��

//1 ��ʽ����ת��
void test01()
{
	//int��double���㣬�Ƚ�int��ʽתΪdouble
	printf("%d\n", sizeof(5 / 2.0));
}

//������ ת С���� �������
void test02()
{
	int a = 353;
	//ԭ�� 256  64  32  1
	//0000 0001 0110 0001

	//char ����  = ԭ��
	//0110 0001 = 64 + 32  + 1 = 97 
	char ch = a;

	printf("%c\n", ch);
}

//char ��short���ڿռ�Ƚ�С�����������������ʱ��ͨ��תΪ int��
void test03()
{
	char a = 10;
	short b = 10;

	printf("%d\n", sizeof(a + a)); //4
	printf("%d\n", sizeof(b + b)); //4
	printf("%d\n", sizeof(a + b)); //4
}

//2 ǿ������ת��
void test04()
{
	float f = 3.14f;

	int num = 0;

	num = (int)f; //ǿ������ת����ֻ����ʱ�ı�f��ֵ

	printf("num = %d\n", num);
	printf("f = %f\n", f);
}

//ע�⣺ǿ��λ�� ����Ҫ
void test05()
{
	float price = 1.6f; //�ƹ� 
	int num = 2;

	int sum = num * (int)price;
	printf("sum = %d\n", sum); // 2

	sum = (int)(num *price);
	printf("sum = %d\n", sum); // 3

}

int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}