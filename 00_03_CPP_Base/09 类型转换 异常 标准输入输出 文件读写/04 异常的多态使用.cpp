#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常 抽象 异常的基类
class BaseException
{
public:
	virtual void printError() = 0;
};

//空指针的异常类
class NULLPointer :public BaseException
{
public:
	void printError()
	{
		cout << "空指针异常" << endl;
	}
};

//数组访问越界
class OutOfRange :public BaseException
{
public:
	void printError()
	{
		cout << "越界异常" << endl;
	}
};

void func()
{
	//throw NULLPointer();
	throw OutOfRange();
}

void test01()
{
	try
	{
		func();
	}
	catch (BaseException & e)
	{
		e.printError();
	}
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}