#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base的默认构造函数调用" << endl;
	}

	~Base()
	{
		cout << "Base的析构函数调用" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "Other的默认构造函数调用" << endl;
	}

	~Other()
	{
		cout << "Other的析构函数调用" << endl;
	}

};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son的默认构造函数调用" << endl;
	}

	~Son()
	{
		cout << "Son的析构函数调用" << endl;
	}

	Other other;
};

void test01()
{
	//Base base;
	// 创建子类对象的时候，先调用父类构造函数，再调用其他类的构造函数，再调用自身的构造函数，析构的顺序与构造是相反的

	Son son;
}


class Base2
{
public:
	//Base2(){}; 解决方式1  父类中添加默认构造
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2的默认构造函数调用" << endl;
	}

	~Base2()
	{
		cout << "Base2的析构函数调用" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	//解决方式2 ，利用初始化列表语法
	Son2(int a = 100) : Base2(a)
	{
		cout << "Son2的默认构造函数调用" << endl;
	}

	~Son2()
	{
		cout << "Son2的析构函数调用" << endl;
	}
};

void test02()
{
	Son2 s;
	cout << s.m_A << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}