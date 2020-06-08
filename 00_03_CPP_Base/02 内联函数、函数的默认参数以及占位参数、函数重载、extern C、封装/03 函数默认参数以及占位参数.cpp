#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数默认参数 

//注意事项1 ：如果函数中有一个默认参数，从这个位置起，后面的值都必须有默认参数
int func(int a, int b = 20 , int c = 20 )
{
	return a + b + c;
}

void test01()
{
	cout << "ret = " << func(10,30) << endl;
}

//注意事项2： 函数的声明和实现只能有一个有默认参数，不可以同时拥有
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
	return a + b;
}

//占位参数
//语法：在函数中只写类型
//用途：目前来说，没啥用途，在学到后面的运算符重载时候，有点用途
//占位参数  可以有默认参数
void func3(int a , int = 10)
{

}
void test02()
{
	func3(10);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}