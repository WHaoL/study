#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base��Ĭ�Ϲ��캯������" << endl;
	}

	~Base()
	{
		cout << "Base��������������" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "Other��Ĭ�Ϲ��캯������" << endl;
	}

	~Other()
	{
		cout << "Other��������������" << endl;
	}

};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son��Ĭ�Ϲ��캯������" << endl;
	}

	~Son()
	{
		cout << "Son��������������" << endl;
	}

	Other other;
};

void test01()
{
	//Base base;
	// ������������ʱ���ȵ��ø��๹�캯�����ٵ���������Ĺ��캯�����ٵ�������Ĺ��캯����������˳���빹�����෴��

	Son son;
}


class Base2
{
public:
	//Base2(){}; �����ʽ1  ���������Ĭ�Ϲ���
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2��Ĭ�Ϲ��캯������" << endl;
	}

	~Base2()
	{
		cout << "Base2��������������" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	//�����ʽ2 �����ó�ʼ���б��﷨
	Son2(int a = 100) : Base2(a)
	{
		cout << "Son2��Ĭ�Ϲ��캯������" << endl;
	}

	~Son2()
	{
		cout << "Son2��������������" << endl;
	}
};

void test02()
{
	Son2 s;
	cout << s.m_A << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}