#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class myException
{
public:

	myException()
	{
		cout << "myException的默认构造函数调用" << endl;
	}

	myException(const myException &)
	{
		cout << "myException的拷贝构造函数调用" << endl;
	}

	~myException()
	{
		cout << "myException的析构函数调用" << endl;
	}

};

void func()
{
	throw new myException();
}

void test01()
{
	try
	{
		func();
	}
	// 用catch (myException e)   throw myException(); 会调用拷贝构造函数，创建新的对象
	// 用catch (myException &e)  throw myException(); 只有一份异常对象    推荐
	// 用catch (myException *e)  throw &myException(); 异常对象会提前被释放，因此不可以使用
	// 用catch (myException *e)  throw new myException(); 逻辑和引用一样的，但是要自己加delete
	catch (myException * e)
	{
		cout << "我自己的异常捕获" << endl;

		delete e;
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}