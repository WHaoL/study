#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常可以是自定义的数据类型
class myException
{
public:
	void printError()
	{
		cout << "我自己的异常" << endl;
	}
};

class Person
{
public:
	Person()
	{
		cout << "Person默认构造" << endl;
	}
	~Person()
	{
		cout << "Person析构函数" << endl;
	}

};

int myDivision(int a ,int b)
{
	if ( b == 0)
	{
		//return -1; //在C语言下 返回-1代表异常的值.导致-1的结果无法区分是异常还是返回值

		//throw 1; //抛出一个int类型异常
		//throw 'a'; //抛出一个char类型异常
		//throw 3.14; //抛出double类型异常

		Person p1;
		Person p2;

		//从try开始，到throw抛出异常前，所有栈上的对象都被释放，析构的顺序与构造的相反的，这个过程称为栈解旋

		throw myException(); //抛出一个myException 异常的对象
	}
	return a / b;
}

void test01()
{
	int a = 10;
	int b = 0;

	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int类型的异常捕获" << endl;
	}
	catch (char)
	{
		cout << "char类型的异常捕获" << endl;
	}
	catch (double d)
	{
		//如果捕获的异常不想处理，想继续向上抛出，利用 throw关键字
		throw;
		cout << "double类型的异常捕获" << endl;
	}
	catch (myException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "其他类型的异常捕获" << endl;
	}

	
	//if ( myDivision(a,b) == -1)
	//{
	//	cout << "出现异常" << endl;
	//}
	//else
	//{
	//	cout << myDivision(a, b) << endl;
	//}
}

int main(){

	try
	{
		test01();
	}
	catch (int)
	{
		cout << "main函数中 int类型的异常捕获" << endl;
	}
	catch (...)
	{
		cout << "main函数中 其他异常捕获" << endl;
	}

	//C++中的异常必须有处理，如果都不处理，程序会自动调用 terminate 函数，让程序终止
	

	system("pause");
	return EXIT_SUCCESS;
}