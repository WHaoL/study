#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1��C++��Ĭ�ϸ�һ�����������3������
// Ĭ�Ϲ���  ����ʵ�֣�
// ��������  ����ʵ�֣�
// ��������  ��ֵ������

//2�����ù���
// ��������ṩ���вι��죬��ô�������Ͳ��ṩ�޲ι����ˣ���Ȼ���ṩ��������
// ��������ṩ�˿������죬��ô�������Ͳ��ṩ������ͨ����
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
	//Person(const Person &p)
	//{
	//	m_Age = p.m_Age;
	//	cout << "Person�Ŀ������캯������" << endl;
	//}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_Age;
};


void test01()
{
	Person p1(100);

	Person p2(p1);

	cout << "p2������Ϊ:" << p2.m_Age << endl;
}

void test02()
{
	Person p;
	Person p1(18);
	Person p2(p1);
	cout << p2.m_Age << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}