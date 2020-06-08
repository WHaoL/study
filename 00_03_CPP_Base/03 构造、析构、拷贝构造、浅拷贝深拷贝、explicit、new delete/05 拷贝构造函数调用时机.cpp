#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

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
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
};

//拷贝构造调用时机

//1、已经创建好的对象 初始化新对象
void test01()
{
	Person p1(18);
	cout << "p1的年龄为： " << p1.m_Age << endl;

	Person p2(p1);
	cout << "p2的年龄为： " << p2.m_Age << endl;
}

//2、值传递方式 给函数参数 传值
void func(Person p)
{
	cout << "p的年龄为： " << p.m_Age << endl;
}
void test02()
{
	Person p1(20);
	func(p1);
}

//3、以值方式  返回局部对象
Person func2()
{
	Person p(30);
	return p;
}

void test03()
{
	Person p1 = func2();
	cout << "p1的年龄为：" << p1.m_Age << endl;
	cout << "p1的年龄为：" << p1.m_Age << endl;
	cout << "p1的年龄为：" << p1.m_Age << endl;
}
/*
Release版本优化
void func2(Person & p)
{
	p.m_Age = 30;
}

Person p1;
func2(p1);

*/

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}