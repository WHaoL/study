#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

template<class T1,class T2>
class Person
{
	friend void printPerson(Person <T1, T2>&p)
	{
		cout << "ȫ�ֺ�������ʵ��--- ������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
	}
	

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//void showPerson()
	//{
	//	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	//}

private:
	T1 m_Name;
	T2 m_Age;
};

void test01()
{
	Person <string,int>p("Tom", 18);
	//p.showPerson();

	printPerson(p);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}