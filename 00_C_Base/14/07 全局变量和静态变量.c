#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��ȫ�ֱ���
//����ʱ��д�ں������ⲿ
//�ڱ��ļ��������ļ��ж�����ʹ��

void test01()
{
	extern int g_a; //���߱�����g_a�ڱ���ļ��У�����ʹ��ʱ��Ҫ����
	printf("g_a = %d\n", g_a);

}

//2����̬����  ֻ���ڱ��ļ���ʹ�ã��ڲ���������
void test02()
{
	//�ֲ���̬����
	static int s_b = 1000; //ֻ�ᱻ��ʼ��һ��
	//extern int s_a;   
	//printf("s_a = %d\n", s_a);  error ��̬���� ֻ���ڱ��ļ���ʹ��
}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}