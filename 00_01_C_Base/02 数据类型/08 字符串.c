#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// �ַ�������
void test01()
{
	// ˫������������� ��Ϊ�ַ�������
	// ˫��������������л�����ַ���������־  \0
	printf("%s\n", "hello world"); 
	// ˫���Ż᷵���ַ��������ַ��ĵ�ַ��� 
	// %s���ʱ ����\0 �������
	printf("sizeof = %d\n", sizeof("hello world")); // 12

	printf("%s\n", "hello\0world");
	printf("%s\n", "\0hello world");
}

// �ַ�������
void test02()
{
	char str[] = "hello world";

	printf("%s\n", str);
	printf("sizeof = %d\n", sizeof(str)); //12

	str[0] = 'x';
	printf("%s\n", str);

	//�����γ��� ����ַ������и��������
}

//�����ź�˫��������
void test03()
{
	char a1 = 'a';
	char a2[] = "a"; // a \0

	//ǰ�����ַ�  �������ַ���

	//ǰ�߱�����ASCII��ֵ������ȡ���ַ�������ĸ��ַ���б���

	//ǰ�� ռ��1���ֽ�  ���� ռ�� 2���ֽ�

}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}