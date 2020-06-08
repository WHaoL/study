#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//值传递
void mySwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

//地址传递
void mySwap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test02()
{
	int a = 10;
	int b = 20;
	mySwap2(&a, &b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//引用传递
void mySwap3(int &a,int &b) // int &a = a , int &b = b;
{
	int temp = a;
	a = b;
	b = temp;
}
void test03()
{
	int a = 10;
	int b = 20;
	mySwap3(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


//引用注意事项
int& func()
{
	int a = 1000;
	return a;
}

void test04()
{
	//1、引用必须引一块合法的内存空间
	int a = 10;
	//int &b = 10; error 10在常量区中，不可以用引用修改内存
	

	//2、不要返回局部变量的引用
	int& ret = func();
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
}



int& func2()
{
	static int a = 1000;
	return a;
}

void test05()
{

	int& ret = func2();

	cout << "ret = " << ret << endl;
	
	//函数的返回值如果是引用，那么函数的调用可以作为左值
	func2() = 10000;

	cout << "ret  = " << ret << endl;
}



int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}