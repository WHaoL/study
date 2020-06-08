#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、静态成员变量
//2、静态成员函数
class Person
{
public:

	Person()
	{
		//m_A = 10;  
		/*
			若想通过创建对象时的默认构造函数初始化静态数据成员。

			通过类名访问数据时，没有对象被生成，也就不会有默认构造函数被调用，
			就不会走初始化的代码，那么静态数据成员就无法被初始化
		*/
	}

	//静态成员函数
	//只有一份函数
	//静态成员函数 也是有访问权限
	static void func()
	{
		cout << "静态成员函数func调用" << endl;
		m_A = 100; //静态成员函数中 可以访问静态成员变量
		//m_C = 100; //静态成员函数中 不可以访问非静态成员变量，无法区分到底是哪个对象修改m_C静态成员变量
	}

	//非静态成员函数 ,可以访问静态成员变量和非静态成员变量
	void func2()
	{
		m_A = 100;
		m_C = 100;
	}

	//静态成员
	//在编译阶段就分配内存
	//所有对象都共享同一个静态成员变量
	//必须在类内声明，类外初始化
	static int m_A;

	int m_C; //非静态成员变量

private:
	static int m_B;

	static void func3()
	{
		cout << "静态成员函数func3调用" << endl;
	}
};

//静态成员变量：类内定义，类外初始化
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	Person p1;
	cout << "p1.m_A =  " << p1.m_A << endl;

	Person p2;
	p2.m_A = 20;

	cout << "p1.m_A =  " << p1.m_A << endl;
}

//访问方式
void test02()
{
	//访问方式1  通过对象访问
	Person p1;
	cout << "p1.m_A =  " << p1.m_A << endl;

	//访问方式2  通过类名访问
	cout << Person::m_A << endl;
}

//静态成员变量 也是有访问权限
void test03()
{
	//m_B属于私有权限属性，因此类外不可以访问
	//cout << "m_B = " << Person::m_B << endl;
}

void test04()
{
	//静态成员函数访问方式 有两种
	//通过对象
	Person p1;
	p1.func();

	//通过类名
	Person::func();

	//Person::func3(); func3私有成员，因此类外访问不到
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}


