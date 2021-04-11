#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person()
	{
		this->m_A = 1000;
	}

	//每个非静态成员函数中都隐藏的添加了this指针
	//  this指针的本质 是一个指针常量
	//  const Person * const this  
	//  const修饰的成员函数 称为 常函数 
	void showM_A()const
	{
		//this = NULL; this指针的指向是不可以修改的
		//this->m_A = 2000; //const函数中，指针指向的值不可以修改
		cout << "showM_A调用" << endl;
		this->m_B = 1000;
		cout << "m_A  = " << this->m_A << endl;
	}
	void func()
	{
		//m_A = 1000;
		cout << "func调用" << endl;
	}

	int m_A;

	mutable int m_B; //加mutable关键字之后，即使在常函数 或 常对象 中，也可以修改
};

void test01()
{
	const Person p1; //const修饰的对象，称为常对象
	//p1.m_A = 1000;
	p1.m_B = 1000; //加mutable关键字修饰后，在常对象中依然可以修改

	p1.showM_A(); //常对象  可以调用 常函数

	//p1.func();    //常对象  不可以调用 普通成员函数

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}