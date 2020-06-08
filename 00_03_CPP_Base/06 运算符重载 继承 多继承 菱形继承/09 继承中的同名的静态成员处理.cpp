#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:

	static void func()
	{
		cout << "base下的func调用" << endl;
	}

	static void func(int a)
	{
		cout << "base下的func(int a)调用" << endl;
	}

	//编译阶段分配内存
	//所有对象共享同一份数据
	//类内声明，类外初始化
	static int m_A;
};
int Base::m_A = 100;

class Son :public Base
{
public:

	static void func()
	{
		cout << "son下的func调用" << endl;
	}

	static int m_A;
};
int Son::m_A = 200;

void test01()
{
	//1、通过对象访问
	Son s;
	cout <<  "Son下的m_A = "  << s.m_A << endl;
	cout <<  "Base下的m_A = " << s.Base::m_A << endl;

	//2、通过类名访问
	cout << "Son下的m_A = " << Son::m_A << endl;
	cout << "Base下的m_A = " << Son::Base::m_A << endl; //第一个双冒号含义，通过类名方式访问数据，第二个代表父类作用域
}


void test02()
{
	//1、通过对象访问
	Son s;
	s.func();
	s.Base::func();

	//2、通过类名访问
	Son::func();
	Son::Base::func();

	Son::Base::func(10);  //子类重定义父类的同名成员后，隐藏所有同名func，如果想调用，加作用域
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}