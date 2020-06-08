#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	//构造函数
	//1 没有返回值  不用写void
	//2 函数名与类名相同
	//3 可以有参数，可以发生重载
	//构造函数由编译器自动调用，无需手动，而且只会调用一次
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}
	//析构函数
	//1 没有返回值  不用写void
	//2 函数名与类名相同 在函数名前面加 ~ 
	//3 不可以有参数，因此不能发生重载
	//析构函数由编译器自动调用，无需手动，而且只会调用一次
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

void test01()
{
	Person p1;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}