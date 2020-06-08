#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};


template<class T>
bool myCompare(T&a, T&b)
{
	if (a==b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体化方式，解决Person类型对比
template<> bool myCompare(Person&a, Person&b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	return false;
}

void test01()
{
	int a = 10;
	int b = 20;

	bool ret= myCompare(a, b);
	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

void test02()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
	
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}