#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1����λȡ��
void test01()
{
	int num = 2;
	printf("~num = %d\n", ~num);   //-3 

	// 0000 0000 0000 0000 0000 0000 0000 0010

	// 1111 1111 1111 1111 1111 1111 1111 1101   ȡ����

	// 1000 0000 0000 0000 0000 0000 0000 0011    - 3 
}

//2����λ�� &
void test02()
{
	int num = 332;

	if ( (num & 1) ==0)
	{
		printf("ż��\n");
	}
	else
	{
		printf("����\n");
	}
}

//3����λ��  |
void test03()
{
	int num1 = 5;
	int num2 = 3;

	printf("num1 | num2 = %d\n", num1 | num2); //7

}

//4����λ���
void test04()
{
	//����ʵ�ֽ�����������
	int num1 = 5;
	int num2 = 10;

	//��ʽһ
	//int temp = num1;
	//num1 = num2;
	//num2 = temp;

	//��ʽ��
	//num1 = num1 ^ num2; 
	//num2 = num1 ^ num2;
	//num1 = num1 ^ num2;

	//��ʽ��
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;


	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
}


//����  << 
void test05()
{
	int num = 10;
	printf("num <<= 3 = %d\n", num <<= 3);  //����nλ�������2 ^n
}

//����  >> 
void test06()
{
	int num = 80;
	printf("num = %d\n", num >>= 2);  //����nλ�������2 ^n
}



int main(){

	test06();

	system("pause");
	return EXIT_SUCCESS;
}