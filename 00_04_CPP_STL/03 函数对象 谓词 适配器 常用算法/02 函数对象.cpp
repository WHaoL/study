//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//1、仿函数，重载()运算符，使得在使用阶段像函数调用
class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
		m_Count++;
	}
	int m_Count = 0;
};
void test01()
{
	MyPrint mp;
	mp("test01------hello world"); //不是真正的函数，而是一个对象
}

//2、仿函数，超出普通函数的概念，可以自己拥有内部的状态
void myPrint(string test)
{
	cout << test << endl;
}

void test02()
{
	MyPrint mp;
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");

	cout << "mp使用次数为： " << mp.m_Count << endl;
}

//3、函数对象 可以作为 函数的参数
void doWork(MyPrint mp, string str)
{
	mp(str);
}

void test03()
{
	MyPrint mp;
	doWork(mp, "hello");
}

int main()
{

	test01();

	test02();
	test03();
	//system("pause");
	return 0;
}