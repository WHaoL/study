#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include "test.h"

//告诉编译器show函数 要用c语言方式链接
//extern "C" void show();


void test01()
{
	show();   //_Z4showv
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}