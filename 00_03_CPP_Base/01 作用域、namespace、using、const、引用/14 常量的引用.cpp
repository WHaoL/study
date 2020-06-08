#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//int &ref = 10;//引用必须引合法内存空间

	const int &ref = 10; //编译器优化代码： int temp = 10;  const int &ref = temp;

	//ref = 1000;

	int * p = (int *)&ref;
	*p = 1000;
	cout << ref << endl;

}

//const使用场景  可以修饰函数形参，防止代码中的误操作
void showNum(const int & a) // const int & a = a;
{
	//a = 10000;
	cout << a << endl;
}

void test02()
{
	int a = 10;
	showNum(a);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}