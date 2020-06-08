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
		cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1��ָ����������  �Ƽ�
void doWork(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person <string, int>p1("Tom", 19);
	doWork(p1);
}

//2������ģ�廯
template<class T1 ,class T2>
void doWork2(Person<T1, T2>&p)
{
	cout << "T1������: " << typeid(T1).name() << endl;
	cout << "T2������: " << typeid(T2).name() << endl;
	p.showPerson();
}

void test02()
{
	Person <string, int>p2("Jerry", 19);
	doWork2(p2);
}

//3�������� ģ�廯
template<class T>
void doWork3( T & p)
{
	cout << "T�����ͣ� " << typeid(T).name() << endl;
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