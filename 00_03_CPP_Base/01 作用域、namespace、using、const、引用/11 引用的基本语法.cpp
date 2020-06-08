#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//引用：给变量起别名
//语法：类型  & 别名 = 原名
void test01()
{
	int a = 10;

	int &b = a;

	b = 20;

	cout << a << endl;
	cout << b << endl;
}

//引用必须初始化
void test02()
{
	int a = 10;
	//int &b;  err 必须初始化引用
	int &b = a;

	//引用一旦初始化后，不可以改变引用的指向
	int c = 20;
	b = c; //不是再改变引用，只能通过引用对原变量进行赋值

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//建立对数组的引用
void test03()
{
	//1、先定义数组的类型，再通过类型定义引用
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(ARRAY_TYPE)[5];
	//类型  & 别名 = 原名
	ARRAY_TYPE & pArr = arr;
	for (int i = 0; i < 5;i++)
	{
		cout << pArr[i] << endl;
	}


	//2、先定义数组引用的类型，在通过类型定义引用
	typedef int(&ARRAY_TYPE_REF)[5];

	ARRAY_TYPE_REF  pArr2 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr2[i] << endl;
	}

	//3、直接定义引用
	int(&pArr3)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr3[i] << endl;
	}
}

int main(){
	test03();


	system("pause");
	return EXIT_SUCCESS;
}