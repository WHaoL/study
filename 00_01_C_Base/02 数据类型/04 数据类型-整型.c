#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����
// short  int  long  longlong 

void test01()
{
	short num1 =  32768; // (-2^15 ~ 2^15-1)    -32768 ~ 32767

	int num2 = 32768;

	long num3 = 10;

	long long num4 = 10;

	printf("num1 = %hd\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %ld\n", num3);
	printf("num4 = %lld\n", num4);
}

//�з��ź��޷��� ����
void test02()
{
	printf("%d\n", 10); //�з�������int  ��%d�������

	printf("%u\n", 10U); //�޷�������int  ��%u�������

	printf("%ld\n", 10L); //�з������� long  ��%ld�������

	printf("%lu\n", 10UL); // �޷�������long  ��%lu�������
}

//�з��ź��޷��� ����
void test03()
{
	signed int a = 10; //Ĭ�����з��ŵı��� ����ǰ�����صļ��˹ؼ��� signed
	printf("%d\n", a);

	unsigned int a2 = 10; //�޷������ͱ��� unsigned��������
	printf("%u\n", a2);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}