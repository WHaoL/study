#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ؼ���
//C������Ԥ�ȱ����ĵ��ʣ����ǲ���������Щ���ʸ����� ����

void test01()
{
	//������ ��Ϊ int
	//int int = 10;
	//int extern = 10;
	//int void = 10;
	//int return = 10;
}


//��ʶ����������  ----  ��������������
//1����ʶ������ �������ǹؼ���
//2����ʶ�� ����ĸ�����֡��»���_ ��� 
//3����һ���ַ�  ��������ĸ �� �»��� ��ͷ
//4����ʶ���е���ĸ ���ִ�Сд
void test02()
{
	
	//int int = 10;  //error
	int abc = 10;
	int abc123 = 10;
	int abc_123 = 10;
	//int 123abc = 10;  //error
	int _123abc = 10;
	int aaa = 10;
	
	//printf("aaa = %d\n", AAA);//error ���ִ�Сд


	//���� ����ʶ��������ʱ�������������֪���Ч������ߴ���Ŀɶ���
	int num1 = 10;
	int num2 = 10;
	int sum = num1 + num2;
	printf("%d\n", sum);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}