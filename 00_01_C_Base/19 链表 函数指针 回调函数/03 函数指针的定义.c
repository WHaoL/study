#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ָ�붨�巽ʽ

//1���ȶ�������������ͣ���ͨ���������Ͷ��庯��ָ��

void func(int a, char b)
{
	printf("hello world\n");
}

void test01()
{
	typedef void(FUNC_TYPE)(int, char); //FUNC_TYPEҲ���������ͣ��������ķ���ֵ��void�������ǣ�int,char��

	FUNC_TYPE * funcP = func;

	funcP(10,'a');
}

//2���ȶ��������ָ������ͣ���ͨ������ָ�����ͣ����庯��ָ�����
void test02()
{
	typedef void(*FUNC_TYPE)(int, char);

	FUNC_TYPE funcP = func;

	funcP(20, 'b');
}

//3��ֱ�Ӷ��庯��ָ�����
void test03()
{
	void(*p)(int, char)  = func;

	p(10, 'x');
}

//4������ָ��  ��  ָ�뺯�� ����
//����ָ�� ��һ��ָ�� ��ָ�����һ���������
//ָ�뺯�� ��һ������ ����������ķ���ֵ������һ��ָ��

//����ָ��  ָ�볣��  ����ָ��  ָ������  ����ָ�� ָ�뺯��


//����ָ������

void func1()
{
	printf("func1��������\n");
}
void func2()
{
	printf("func2��������\n");
}
void func3()
{
	printf("func3��������\n");
}

void test04()
{
	//����ָ�����鶨��
	void(*func_arr[3])();

	func_arr[0] = func1;
	func_arr[1] = func2;
	func_arr[2] = func3;

	for (int i = 0; i < 3;i++)
	{
		func_arr[i]();
	}

}



int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}