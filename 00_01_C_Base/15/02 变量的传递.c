#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void b()
{
	int aaa = 10;//�� b�д�����ջ�ϱ�����main���� �� a ���޷�ʹ��
}

void a()
{
	int aa = 10; //��a�д�����ջ�ϱ�����main�������޷�ʹ�ã�b�� ����ʹ��

	b();
}

int main(){

	//int aa = 10;  ���������д�����ջ�ϱ�������a��b�ж�����ʹ��

	a();

	system("pause");
	return EXIT_SUCCESS;
}