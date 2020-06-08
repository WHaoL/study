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

	//重载==
	bool operator==(Person &p)
	{
		//if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		//{
		//	return true;
		//}
		//return false;

		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	//重载!=
	bool operator!=(Person &p)
	{
		return !(this->m_Name == p.m_Name && this->m_Age == p.m_Age);
	}

	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

void test01()
{
	int a = 10;
	int b = 20;
	if (a == b)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);

	if (p1 == p2)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}

	if (p1 != p2)
	{
		cout << "p1 != p2 " << endl;
	}
	else
	{
		cout << "p1 == p2 " << endl;
	}
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}