#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int atk = 100;

void test01()
{
	int atk = 200;
	//就近原则
	cout << "局部atk = " << atk << endl;

	//:: 如果在::前没有任何作用域，代表使用全局作用域
	cout << "全局atk = " << ::atk << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}