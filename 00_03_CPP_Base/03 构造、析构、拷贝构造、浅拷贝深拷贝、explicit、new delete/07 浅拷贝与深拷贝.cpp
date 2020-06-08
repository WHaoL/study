#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(char * name ,int age)
	{
		cout << "Person���вι��캯������" << endl;

		//��name���䵽����
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_Age = age;
	}

	//�������캯��
	Person(const Person & p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = p.m_Age;

		//m_Name = p.m_Name; //�������ṩ��ǳ��������

		m_Name =(char *)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
	}

	~Person()
	{
		//����������������
		cout << "Person��������������" << endl;

		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}

	char * m_Name;
	int m_Age;
};

void test01()
{
	Person p1("Tom", 18);
	cout << "p1 ������ " << p1.m_Name << " ���䣺 " << p1.m_Age << endl;

	Person p2(p1);
	cout << "p2 ������ " << p2.m_Name << " ���䣺 " << p2.m_Age << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}