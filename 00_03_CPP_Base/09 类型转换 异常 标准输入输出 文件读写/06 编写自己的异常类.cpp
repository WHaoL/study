// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdexcept>

//我的越界异常类
class MyOutOfRange : public exception
{
public:
	MyOutOfRange(const string &errInfo)
	{
		this->m_ErrorInfo = errInfo;
	}

	MyOutOfRange(const char *errInfo)
	{
		//const char * 转为 string
		this->m_ErrorInfo = string(errInfo);
	}

	// noexcept 说明符 (C++11 起)   指定函数是否抛出异常。
	// 语法：
	//		noexcept 			(1)
	// 		noexcept(表达式) 	(2)
	// 说明：
	// 1) 与 noexcept ( true ) 相同
	// 2) 若 表达式 求值为 true，则声明函数为不抛出任何异常。
	virtual const char *what() const noexcept(true)
	{
		//string 转为  const char *
		return this->m_ErrorInfo.c_str();
	}

	// noexcept 运算符(C++11) 	确定表达式是否会抛出任何异常
	// throw 表达式 			引发错误并将控制转移到错误处理块
	// move_if_noexcept(C++11)	若移动构造函数不抛出则获得右值引用 (函数模板)

	string m_ErrorInfo; //维护错误信息
};

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//throw out_of_range("年龄应该在0~150之间");
			throw MyOutOfRange("我自己的异常 --- 年龄应该在0~150之间 ");
		}

		this->m_Age = age;
	}

	int m_Age;
};

void test01()
{
	try
	{
		Person p1(151);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

int main()
{

	test01();

	// system("pause");
	return EXIT_SUCCESS;
}