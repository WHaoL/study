#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��extern
void test01()
{
	//���������ã�����ʱ��û�и����������ڴ�ռ�
	extern int a;
	printf("a = %d\n", a);
}
int  a = 10;

//2��const
void test02()
{
	//��const�޶�������ʱ���ñ�����Ϊֻ��״̬������
	const int b = 10;

	printf("b = %d\n", b);
	
	//b = 1000;  error  b�ǳ���
}

//3��register �Ĵ�������
void test03()
{
	register int num = 10;
	printf("%d\n", num);
	
	//printf("%d\n", &num); //error �Ĵ������� ������ȡ��ַ
}

//4��volatile ��ֹ�������Ż�����
void test04()
{
	volatile int num = 10;
	num = 100;
	num = 100;
	num = 120;
	num = 130;
	num = -10;
	num = 100;

	//�������п����Ż���  ֻ��һ�е� num = 100;�Ĵ���
	//Ϊ�˷�ֹ�������Ż������Լ�volatile
	
	//�����Щ������Ҫʵʱ�ļ�飬��ô���Լ��Ϲؼ���
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}