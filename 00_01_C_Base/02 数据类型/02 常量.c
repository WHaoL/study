#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DAY 7

//���� �ڳ��������ڼ� �����Ըı����
void test01()
{
	//һ����5�ֱ��ֵ���ʽ

	//1����ֵ����(�����ͳ����������� ��ʵ���ͳ�����С����)  
	// 100 200 300  3.14   1.1 2.2 3.3
	//100 = 200; //error �����ǲ������޸ĵģ�

	//2���ַ�����  'a' 'b' 'c' '\n' '\t'
	//'a' = 'b'; error

	//3���ַ�������  "hello world"
	//"hello world" = "aaaa"; error

	//4�����ų���  ���곣����
	//���� #define 
	printf("һ��һ����%d��\n", DAY);
	//DAY = 14; error

	//5��const ���εı��� 
	const int month = 12;
	printf("һ��һ����%d��\n", month);
	//month = 24;  error  ��ʱ��һ�������� �������޸�
	
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}