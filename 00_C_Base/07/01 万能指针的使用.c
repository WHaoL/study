#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//void //������
	//int a = 10;
	//void b = 20;  ������ͨ�������ʹ�������
}
void test02()
{
	void * p = NULL; //4���ֽ�
	printf("sizeof p = %d\n", sizeof(void *));

	int a = 10;
	p = &a;

	//void * �����Խ�����
	printf("a = %d\n", *(int*)p);

	//void * ͨ���������������������͵ĵ�ַ���������Ҳ��Ϊ��������ָ��
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}