#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:

	static void func()
	{
		cout << "base�µ�func����" << endl;
	}

	static void func(int a)
	{
		cout << "base�µ�func(int a)����" << endl;
	}

	//����׶η����ڴ�
	//���ж�����ͬһ������
	//���������������ʼ��
	static int m_A;
};
int Base::m_A = 100;

class Son :public Base
{
public:

	static void func()
	{
		cout << "son�µ�func����" << endl;
	}

	static int m_A;
};
int Son::m_A = 200;

void test01()
{
	//1��ͨ���������
	Son s;
	cout <<  "Son�µ�m_A = "  << s.m_A << endl;
	cout <<  "Base�µ�m_A = " << s.Base::m_A << endl;

	//2��ͨ����������
	cout << "Son�µ�m_A = " << Son::m_A << endl;
	cout << "Base�µ�m_A = " << Son::Base::m_A << endl; //��һ��˫ð�ź��壬ͨ��������ʽ�������ݣ��ڶ���������������
}


void test02()
{
	//1��ͨ���������
	Son s;
	s.func();
	s.Base::func();

	//2��ͨ����������
	Son::func();
	Son::Base::func();

	Son::Base::func(10);  //�����ض��常���ͬ����Ա����������ͬ��func���������ã���������
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}