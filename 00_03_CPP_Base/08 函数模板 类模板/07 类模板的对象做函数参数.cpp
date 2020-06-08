#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

template<class T1 ,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型  推荐
void doWork(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person <string, int>p1("Tom", 19);
	doWork(p1);
}

//2、参数模板化
template<class T1 ,class T2>
void doWork2(Person<T1, T2>&p)
{
	cout << "T1的类型: " << typeid(T1).name() << endl;
	cout << "T2的类型: " << typeid(T2).name() << endl;
	p.showPerson();
}

void test02()
{
	Person <string, int>p2("Jerry", 19);
	doWork2(p2);
}

//3、整个类 模板化
template<class T>
void doWork3( T & p)
{
	cout << "T的类型： " << typeid(T).name() << endl;
	p.showPerson();
}

void test03()
{
	Person <string, int>p3("Jerry", 29);
	doWork3(p3);
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}