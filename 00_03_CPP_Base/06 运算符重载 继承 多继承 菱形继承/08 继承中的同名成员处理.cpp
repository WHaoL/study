#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 100;
	}

	void func()
	{
		cout << "Base�µ�func����" << endl;
	}

	void func(int a)
	{
		cout << "Base�µ�func(int a)����" << endl;
	}

	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		this->m_A = 200;
	}
	void func()
	{
		cout << "Son�µ�func����" << endl;
	}
	int m_A;
};

//1��ͬ���ĳ�Ա����
void test01()
{
	Son s;
	cout << "Son�е�m_A = " << s.m_A << endl;
	//���ø��������� ���Է��ʸ�����ͬ����m_A
	cout << "Base�е�m_A = " << s.Base::m_A << endl;
}

//2��ͬ���ĳ�Ա����
void test02()
{
	Son s;
	s.func(); //���ȵ��������func����

	s.Base::func(); //����ͨ����������ʵ������ͬ����Ա����

	//�������븸���еĳ�Ա��������ͬ����ʱ����������ص����������е�ͬ����Ա����
	//�������ã�����������
	//�������¶��常���ͬ����Ա�������ض���
	s.Base::func(10);
	
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}