#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include "person.hpp"


void test01()
{
	Person <string, int>p("aaa", 200);
	p.showPerson();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}