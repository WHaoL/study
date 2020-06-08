#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、using 声明
namespace KingGlory
{
	int sunwukongId = 1;
}
void test01()
{
	int sunwukongId = 2;

	//当using声明和就近原则同时出现，代码产生二义性，尽量避免
	// 告诉编译器后面使用的是 KingGlory作用域下的 sunwukongId
	//using KingGlory::sunwukongId;
	cout << "sunwukongId = " << sunwukongId << endl;
}

//2、using编译指令 

namespace LOL
{
	int sunwukongId = 3;
}

void test02()
{

	//int sunwukongId = 2;

	//编译指令
	//当就近原则与using指令同时出现，优先使用是就近原则
	using namespace KingGlory;
	using namespace LOL;
	//当using声明有同名情况出现，需要加作用域区分

	cout << "sunwukongId = " << LOL::sunwukongId << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}