#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1的show调用" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2的show调用" << endl;
	}
};


template<class T>
class MyClass
{
public:

	//类模板中的成员函数，一开始是不会创建出来的，只有运行时确定T，才创建这个函数
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

void test01()
{
	MyClass <Person1>mc;
	//mc.func1();
	//mc.func2();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}