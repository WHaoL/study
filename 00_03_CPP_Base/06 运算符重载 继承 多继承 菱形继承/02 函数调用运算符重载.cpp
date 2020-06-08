#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class myPrint
{
public:

	//重载 ()
	void operator()(string text)
	{
		cout << text << endl;
	}

};

void MyPrint(string text)
{
	cout << text << endl;
}

void test01()
{
	myPrint mp;
	mp("hello world"); // 仿函数  使用方面很像函数的调用，因此称为仿函数
	//本质是一个对象，因此我们称这样的对象为 函数对象

	MyPrint("hello world");
}

//仿函数非常灵活，没有固定的写法
class MyAdd
{
public:
	int operator()(int a ,int b)
	{
		return a + b;
	}
};

void test02()
{
	/*MyAdd add;
	cout << add(10, 10) << endl;*/

	cout << MyAdd()(10, 10) << endl;//匿名函数对象  特点：当前行执行完，立即释放
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}