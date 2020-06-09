//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

template <class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}

	void showPerson();
	//{
	//	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	//}

	T1 m_Name;
	T2 m_Age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
}

void test01()
{
	Person<string, int> p("aaa", 100);
	p.showPerson();
}

int main()
{

	test01();

	//system("pause");
	return EXIT_SUCCESS;
}