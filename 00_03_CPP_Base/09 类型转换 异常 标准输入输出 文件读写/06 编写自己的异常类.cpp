#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdexcept>


//我的越界异常类
class MyOutOfRange :public exception
{
public:

	MyOutOfRange(const string& errInfo)
	{
		this->m_ErrorInfo = errInfo;
	}

	MyOutOfRange(const char * errInfo)
	{
		//const char * 转为 string
		this->m_ErrorInfo = string(errInfo);
	}

	virtual const char *  what() const
	{
		//string 转为  const char *
		return this->m_ErrorInfo.c_str();
	}


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
			throw MyOutOfRange( "我自己的异常 --- 年龄应该在0~150之间 ");
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
	catch (exception & e)
	{
		cout << e.what() << endl;
	}
}

int main(){

	//test01();



	system("pause");
	return EXIT_SUCCESS;
}