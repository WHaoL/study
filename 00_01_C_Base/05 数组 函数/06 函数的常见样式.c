#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//	1���޲��޷�
void func1()
{
	printf("this is func1\n");
}

//	2���в��޷�
void func2(int a)
{
	printf("this is func2 a = %d\n",a);
	return; //��ѡ���
}

//	3���޲��з�
int func3()
{
	printf("this is func3\n");
	return 1000;
}

//	4���в��з�  �β��еı����� C������ ����д
int func4(int a)
{
	printf("this is func4 a = %d\n",a);
	return a;
}

void test01()
{
	//1���޲��޷�
	func1();
	//2�� �в��޷�
	func2(10);
	//3���޲��з�  ����ֵ �����ڵ���ʱ����ܻ��߲�����
    int num = func3();
	printf("num = %d\n", num);
	//4���в��з�
	int num2 = func4(10000);
	printf("num2 = %d\n", num2);

}


//���庯������ȡ 1 ~  10֮�������
int getRandom(int min,int max)
{

	int random = rand() % max + min;     // 1 ~ 100  max=100 min=1

	return random;
}

void test02()
{
	//�������������
	srand((size_t)time(NULL)); //size_t �ȼ��� unsigned int

	//printf("%d\n", time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int random = getRandom(1, 100); // 1 ~ 100
		printf("random = %d\n", random);
	}

	
}



int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}