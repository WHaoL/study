#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ȫ�ֱ���   ����ȫ����
int g_a = 10;
int g_b = 20;

//ȫ�ֳ���
const int c_g_a = 100;
const int c_g_b = 100;

void test01()
{
	//�ֲ�����  ����ջ��
	int a = 10;
	int b = 20;

	printf("�ֲ�����a�ĵ�ַΪ%d\n", &a);
	printf("�ֲ�����b�ĵ�ַΪ%d\n", &b);

	printf("ȫ�ֱ���g_a�ĵ�ַΪ%d\n", &g_a);
	printf("ȫ�ֱ���g_b�ĵ�ַΪ%d\n", &g_b);


	//��̬����  ����ȫ����
	static int s_a = 10;
	static int s_b = 20;
	printf("��̬�ֲ�����s_a�ĵ�ַΪ%d\n", &s_a);
	printf("��̬�ֲ�����s_b�ĵ�ַΪ%d\n", &s_b);

	//����  ����ȫ����
	printf("�ַ��������ĵ�ַΪ%d\n", &"hello world");
	printf("�ַ��������ĵ�ַΪ%d\n", &"hello C");

	//ȫ�ֳ���   ����ȫ����
	printf("ȫ�ֳ���c_g_a�ĵ�ַΪ%d\n", &c_g_a);
	printf("ȫ�ֳ���c_g_b�ĵ�ַΪ%d\n", &c_g_b);


	char * ch = malloc(4); //malloc���صľ��������ڴ�ռ���׵�ַ
	printf("��������ch�ĵ�ַΪ%d\n", ch);

}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}