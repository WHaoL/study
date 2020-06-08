#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

template<class T1, class T2> class Person;
template<class T1,class T2> void printPerson(Person <T1, T2>&p);


template<class T1, class T2>
void printPerson2(Person <T1, T2>&p)
{
	cout << "全局函数类外实现--- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//加<>空模板参数列表，变为函数模板的声明
	friend void printPerson<>(Person <T1, T2>&p); //普通函数 还是函数模板？？

	friend void printPerson2<>(Person <T1, T2>&p); 

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
void printPerson(Person <T1, T2>&p)
{
	cout << "全局函数类外实现--- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

void test01()
{
	Person <string, int>p("Jerry", 18);

	printPerson(p);

	printPerson2(p);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}