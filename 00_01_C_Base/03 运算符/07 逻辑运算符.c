#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�߼���  !
void test01()
{
	int a = 10;
	printf("!a = %d\n", !a); //0
	printf("!!a = %d\n", !!a); //1

	printf("%d\n", !100); // 0
	printf("%d\n", !!100); // 1
	printf("%d\n", !-100); // 0

	//���㶼���棡����
}

//�߼���
void test02()
{
	//ͬ��Ϊ��  һ��Ϊ��
	int a = 10;
	int b = 20;
	printf(" a && b = %d\n", a && b); //1

	a = 10;
	b = 0;
	printf(" a && b = %d\n", a && b); //0


	a = 0;
	b = 0;
	printf(" a && b = %d\n", a && b); //0


	//ע�⣺ֻ�б��ʽ1  Ϊ�� ���Ż��жϱ��ʽ2      ��·����
	4 < 3 && printf("hello1\n");

	4 > 3 && printf("hello2\n");
}

//�߼���
void test03()
{
	// ͬ��Ϊ��  һ��Ϊ�� ||

	int a = 10;
	int b = 10;
	printf("a || b = %d\n", a || b); // 1

	a = 0;
	b = 10;
	printf("a || b = %d\n", a || b); // 1

	a = 0;
	b = 0;
	printf("a || b = %d\n", a || b); // 0

	//ע�⣺ֻ�б��ʽ1Ϊ��  ���жϱ��ʽ2   ��·����
	4 < 3 || printf("hello1\n"); //ִ��hello1
	4 > 3 || printf("hello2\n"); //��ִ�� hello2
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}