#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���ŵ����ȼ����ڻ�������в����� 
//�������ȼ���ԽС�����ȼ�Խ��
//ͬһ���ȼ��У��������
void test01()
{
	int a = 10;

	//�����Լ������  ���ȼ����� * /
	printf("%d\n", ++a * 10); // 110
}

void test02()
{
	//�Ƚ������ ���� ��ֵ�����
	int a = 10;
	printf("%d\n", a = 23 > 24); // 0
}

void test03()
{
	// �߼���  ���� �߼���
	printf("%d\n", 1 || 1 && 0); //1

}

void test04()
{
	int a = 10;
	//ͬһ������ ��ֵ���� ����������
	//a += a -= a *= a /= 3;
	
	printf("a = %d\n", a); //0
}

// , ���ȼ���͵�
void test05()
{
	int num = 0;
	num = 1, 2, 3, 4;  //�ȸ�ֵ
	printf("num = %d\n", num); //1 

	num = (1, 2, 3, 4); //1 2 3 4 �ȿ������  ��4 ��ֵ��num
	printf("num = %d\n", num); //4  
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}