#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������� ��������������ͬ
//����������������
// 1��ͬһ����������
// 2������������ͬ
// 3�������ĸ�����ͬ���������Ͳ�ͬ������˳��ͬ 


//class Person
//{
//	void func()
//	{
//
//	}
//
//};

void func()
{
	cout << "func()����" << endl;
}

void func(int a)
{
	cout << "func(int a)����" << endl;
}

void func(double a)
{
	cout << "func(double a)����" << endl;
}

void func(int a ,double b)
{
	cout << "func(int a ,double b)����" << endl;
}

void func(double a, int b)
{
	cout << "func(double a ,int b)����" << endl;
}

//�����ķ���ֵ �Ƿ������Ϊ�������ص�������
//����ֵ��������Ϊ������������
//int func(double a, int b)
//{
//	cout << "func(double a ,int b)����" << endl;
//	return 100;
//}
void test01()
{
	func(3.14,10);
}


//��������ע������
//1�������������õ������汾
//��const�Ͳ���const���Թ���
void myFunc(int &a) // int &a = 10;
{
	cout << "myFunc (int & a) �ĵ���" << endl;
}
void myFunc(const int &a)// const int &a = 10;
{
	cout << "myFunc (const int & a) �ĵ���" << endl;
}
//��������ʱ�򣬱���д���� ͬʱдֵ����
//void myFunc(int a)
//{
//	cout << "myFunc (int a) �ĵ���" << endl;
//}

void test02()
{
	int a = 10;
	myFunc(10);
}

//2����������ʱ�򣬾�����Ҫ��Ĭ�ϲ���
void myFunc2(int a)
{
	cout << "myFunc2 int a ����" << endl;
}

void myFunc2(int a , int b = 10)
{
	cout << "myFunc2 int a int b ����" << endl;
}


void test03()
{
	//myFunc2(10); //error �������������Ե��ã�����������
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}