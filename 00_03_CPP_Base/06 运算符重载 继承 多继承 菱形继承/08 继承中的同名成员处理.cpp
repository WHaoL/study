#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 100;
	}

	void func()
	{
		cout << "Base下的func调用" << endl;
	}

	void func(int a)
	{
		cout << "Base下的func(int a)调用" << endl;
	}

	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		this->m_A = 200;
	}
	void func()
	{
		cout << "Son下的func调用" << endl;
	}
	int m_A;
};

//1、同名的成员属性
void test01()
{
	Son s;
	cout << "Son中的m_A = " << s.m_A << endl;
	//利用父类作用域 可以访问父类中同名的m_A
	cout << "Base中的m_A = " << s.Base::m_A << endl;
}

//2、同名的成员函数
void test02()
{
	Son s;
	s.func(); //优先调用子类的func函数

	s.Base::func(); //可以通过作用域访问到父类的同名成员函数

	//当子类与父类中的成员函数出现同名的时候，子类会隐藏掉父类中所有的同名成员函数
	//如果想调用，利用作用域
	//子类重新定义父类的同名成员函数，重定义
	s.Base::func(10);
	
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}