#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//普通函数和函数模板 区别
template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}


void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a - 97 
	//cout << myPlus(a, c) << endl; //自动类型推导 推导不出一致的T，无法调用 ，无法进行隐式类型转换
	cout << myPlus2(a, c) << endl; //普通函数可以发生隐式类型转换

	myPlus<int>(a, c); //显示指定类型 可以 隐式类型转换

}

//普通函数和函数模板的调用规则

//函数模板通过具体类型产生不同的函数
//通过函数模板产生的函数 ，称为  模板函数

template<class T>
void myPrint(T a ,T b)
{
	cout << "函数模板的调用" << endl;
}
/*
void myPrint(int a ,int b)
{
cout << "函数模板的调用" << endl;
}

void myPrint(double a ,double b)
{
cout << "函数模板的调用" << endl;
}
*/

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "函数模板myPrint(T a, T b,T c)的调用" << endl;
}

void myPrint(int a, int b)
{
	cout << "普通函数的调用" << endl;
}

void test02()
{
	//1、如果普通函数和函数模板都可以匹配成功，优先选择普通函数
	int a = 10;
	int b = 20;
	//myPrint(a, b);

	//2、如果想强制走函数模板的内容，需要利用空模板参数列表
	//myPrint<>(a, b);

	//3、函数模板也可以发生函数重载
	//myPrint(a, b, 10);

	//4、如果函数模板可以产生更好的匹配，那么优先选择函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}