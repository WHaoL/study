#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class Base
{
public:
	T m_A;
};

// 当子类的父亲是一个类模板时候，
// 必须要指定出父类中的T类型，否则无法给子类分配内存
class Son : public Base<int>
{
};

template <class T>
class Base2
{
public:
	T m_A;
};

template <class T1, class T2>
class Son2 : public Base2<T2>
{
public:
	Son2()
	{
		cout << "T1的类型为： " << typeid(T1).name() << endl;
		cout << "T2的类型为： " << typeid(T2).name() << endl;
	}
	T1 m_B;
};

void test01()
{
	Son2<string, int> s;
}

int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;
}