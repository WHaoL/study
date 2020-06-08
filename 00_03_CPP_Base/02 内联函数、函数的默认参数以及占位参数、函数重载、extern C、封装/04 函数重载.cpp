#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数重载 ，函数名可以相同
//函数重载满足条件
// 1、同一个作用域下
// 2、函数名称相同
// 3、参数的个数不同、或者类型不同、或者顺序不同 


//class Person
//{
//	void func()
//	{
//
//	}
//
//};

void func()
{
	cout << "func()调用" << endl;
}

void func(int a)
{
	cout << "func(int a)调用" << endl;
}

void func(double a)
{
	cout << "func(double a)调用" << endl;
}

void func(int a ,double b)
{
	cout << "func(int a ,double b)调用" << endl;
}

void func(double a, int b)
{
	cout << "func(double a ,int b)调用" << endl;
}

//函数的返回值 是否可以作为函数重载的条件？
//返回值不可以作为函数重载条件
//int func(double a, int b)
//{
//	cout << "func(double a ,int b)调用" << endl;
//	return 100;
//}
void test01()
{
	func(3.14,10);
}


//函数重载注意事项
//1、函数重载引用的两个版本
//加const和不加const可以共存
void myFunc(int &a) // int &a = 10;
{
	cout << "myFunc (int & a) 的调用" << endl;
}
void myFunc(const int &a)// const int &a = 10;
{
	cout << "myFunc (const int & a) 的调用" << endl;
}
//函数重载时候，避免写引用 同时写值传递
//void myFunc(int a)
//{
//	cout << "myFunc (int a) 的调用" << endl;
//}

void test02()
{
	int a = 10;
	myFunc(10);
}

//2、函数重载时候，尽量不要用默认参数
void myFunc2(int a)
{
	cout << "myFunc2 int a 调用" << endl;
}

void myFunc2(int a , int b = 10)
{
	cout << "myFunc2 int a int b 调用" << endl;
}


void test03()
{
	//myFunc2(10); //error 上面两个都可以调用，产生二义性
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}