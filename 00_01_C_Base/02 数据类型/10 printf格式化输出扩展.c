#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int a = 10;
	printf("ʮ��������� %d\n", a);
	printf("�˽�������� %#o\n", a);
	printf("ʮ����������� %#x\n", a);
	printf("ʮ����������� %#X\n", a);
}

void test02()
{
	int a = 123;   //ʮ����
	int b = 0123;  //�˽���
	int c = 0xabc; //ʮ����������

	printf("%d\n", a);
	printf("%#o\n", b);
	printf("%#x\n", c);
}
//������չ
void test03()
{
	//�����ն�����ʾ�Ŀ�� ,Ĭ���������Ҷ���
	printf("##%5d##\n", 123);
	printf("##%2d##\n", 123);

	printf("##%-5d##\n", 123); //���������


	printf("##%05d##\n", 123); //��0���ո�λ��

	//ע�⣺ 0 �� - �����Թ����   %-05d    0����Ч��
	printf("##%-05d##\n", 123);
}
int main(){

	//test03();
	int k = -8567; printf("|%06d|\n", k);
	system("pause");
	return EXIT_SUCCESS;
}