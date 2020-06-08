#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


void func(double d)
{
	cout << "func double 调用" << endl;
}

void func(float d)
{
	cout << "func float 调用" << endl;
}

void test01()
{
	//宏常量不重视作用域
	#define  PI 3.14

	const float Pi = 3.14;

	//宏常量 没有数据类型区分
	func(Pi);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}