#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int类型交换
void swapInt(int&a ,int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

//double类型
void swapDouble(double&a, double&b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板实现交换
template<typename T> //T代表通用的数据类型，告诉编译器下面紧跟着的函数或者类中出现了T，不要报错
void mySwap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySwap2()
{
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);
	char c = 'c';
	//1、自动类型推导，必须推导出一致的T类型，否则无法调用
	//mySwap(a, c); error 无法推导出一致的T

	//2、显示指定类型
	mySwap<int>(a, b);

	//注意事项，模板不可以独立使用，必须确定T类型
	mySwap2<double>();

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double d1 = 1.1;
	double d2 = 2.2;
	//swapDouble(d1, d2);
	mySwap(d1, d2);
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}