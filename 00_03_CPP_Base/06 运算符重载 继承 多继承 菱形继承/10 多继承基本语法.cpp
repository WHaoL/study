#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};

//语法： class 子类 ： 继承方式 父类1 ， 继承方式 父类2 
class Son :public Base1, public Base2
{
public:
	int m_C;
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;

	Son s;
	//如果父类中有同名成员，需要加作用域区分
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}