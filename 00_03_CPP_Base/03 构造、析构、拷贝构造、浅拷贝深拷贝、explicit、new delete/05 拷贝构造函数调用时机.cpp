#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//�޲�
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	//�в�
	Person(int age)
	{
		m_Age = age;
		cout << "Person���вι��캯������" << endl;
	}

	//��������  ���� -- ����  -- ��¡
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_Age;
};

//�����������ʱ��

//1���Ѿ������õĶ��� ��ʼ���¶���
void test01()
{
	Person p1(18);
	cout << "p1������Ϊ�� " << p1.m_Age << endl;

	Person p2(p1);
	cout << "p2������Ϊ�� " << p2.m_Age << endl;
}

//2��ֵ���ݷ�ʽ ���������� ��ֵ
void func(Person p)
{
	cout << "p������Ϊ�� " << p.m_Age << endl;
}
void test02()
{
	Person p1(20);
	func(p1);
}

//3����ֵ��ʽ  ���ؾֲ�����
Person func2()
{
	Person p(30);
	return p;
}

void test03()
{
	Person p1 = func2();
	cout << "p1������Ϊ��" << p1.m_Age << endl;
	cout << "p1������Ϊ��" << p1.m_Age << endl;
	cout << "p1������Ϊ��" << p1.m_Age << endl;
}
/*
Release�汾�Ż�
void func2(Person & p)
{
	p.m_Age = 30;
}

Person p1;
func2(p1);

*/

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}