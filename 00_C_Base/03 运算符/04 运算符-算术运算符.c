#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���������  + - * /
void test01()
{
	int a = 10;
	int b = 3;
	

	printf("a + b = %d\n", a + b); //13
	printf("a - b = %d\n", a - b); //7
	printf("a * b = %d\n", a * b); //30
	printf("a / b = %d\n", a / b); //3  �����������  ���Ҳ��������С������������


	int a2 = 10;
	int b2 = 20;
	printf("a2 / b2 = %d\n", a2 / b2); // 0

	int a3 = 10;
	int b3 = 0;
	//printf("a3 / b3 = %d\n", a3 / b3);//error ����������Ϊ0

	//����С��֮�� �ǿ��������������
	double d1 = 0.5;
	double d2 = 0.25;
	printf("d1 / d2 = %lf\n", d1 / d2);
}

//ȡģ  ȡ�� ����
void test02()
{
	int a1 = 10;
	int b1 = 3;

	printf("10 %% 3 = %d\n", a1 % b1);

	int a2 = 10;
	int b2 = 20;

	printf("a2 %% b2 = %d\n", a2 % b2); // 10

	int a3 = 10;
	int b3 = 0;
	//printf("a3 %% b3 = %d\n", a3 % b3);  //error

	double d1 = 5.3;
	double d2 = 1.1;
	//����С�����ԣ��ǲ�����ȡ����
	//printf("d1 %% d2 = %lf\n", d1 %d2);//error 
}

void test03()
{
	int num = 5678;

	printf("ǧλ�� = %d\n", num / 1000); //1234 / 1000 = 1
	printf("��λ�� = %d\n", num % 1000 / 100); // 1234 % 1000 = 234  / 100 = 2
	printf("ʮλ�� = %d\n", num %100/10); // 1234 % 100 = 34  / 10  = 3
	printf("��λ�� = %d\n", num % 10); // 1234 % 10 = 4
}

void test04()
{
	//���� ����
	// ++

	////���õ���
	//int a = 10;
	//a++; // a = a + 1;
	//printf("a = %d\n", a);

	////ǰ�õ���
	//int b = 10;
	//++b; // b = b+1;
	//printf("b = %d\n", b);

	//��Ϊ������䣬ǰ�úͺ���û������
	//�����л������ʱ����������


	////ǰ��++  �ȶԱ��� ���� ++ �� ������ʽ
	//int a3 = 10;
	//int b3 = ++a3 * 10; // a3 = a3 + 1   b3 = a3 * 10
	//printf("a3 = %d\n", a3); //11
	//printf("b3 = %d\n", b3); //110 


	////����++ �ȼ�����ʽ   �ٶԱ�������++����
	//int a4 = 10;
	//int b4 = a4++ * 10; 
	//printf("a4 = %d\n", a4); //11
	//printf("b4 = %d\n", b4); //100  

	//���飺��Ҫ��һ�����ʽ�� ����ǰ�����к���  �ɶ���̫��
	int num1 = 10;
	int num2 = 10;

	num2 = ++num1* num1++ - ++num1;

	printf("num1 = %d\n", num1); // 13    
	printf("num2 = %d\n", num2); // 132


}

int main(){

	test04();


	system("pause");
	return EXIT_SUCCESS;
}