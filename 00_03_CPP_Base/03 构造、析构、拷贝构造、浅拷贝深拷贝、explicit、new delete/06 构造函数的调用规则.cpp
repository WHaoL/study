#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、C++会默认给一个类至少添加3个函数
// 默认构造  （空实现）
// 析构函数  （空实现）
// 拷贝构造  （值拷贝）

//2、调用规则
// 如果我们提供了有参构造，那么编译器就不提供无参构造了，依然会提供拷贝构造
// 如果我们提供了拷贝构造，那么编译器就不提供其他普通构造
class Person
{
public:
	//无参
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	//有参
	Person(int age)
	{
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造  拷贝 -- 复制  -- 克隆
	//Person(const Person &p)
	//{
	//	m_Age = p.m_Age;
	//	cout << "Person的拷贝构造函数调用" << endl;
	//}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
};


void test01()
{
	Person p1(100);

	Person p2(p1);

	cout << "p2的年龄为:" << p2.m_Age << endl;
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