#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、宏缺陷1，在运算时候加括号保证完整性
#define MYADD(x,y) ((x) +(y))
void test01()
{
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b) * 20;
	cout << ret << endl;
}

//2、宏缺陷2，即使加了括号，有些情况依然与预期效果不符
//取小值
#define MYCOMPARE(a,b)   (((a) < (b)) ? (a) : (b))

//普通函数
int myCompare(int a, int b)
{
	return a < b ? a : b;
}

void test02()
{
	int a = 10;
	int b = 20;

	//int ret = MYCOMPARE(++a, b); //预期返回结果 11  (((++a) < (b)) ? (++a) : (b)) 实际输出12

	int ret = myCompare(++a, b); //普通函数与预期效果符合
	cout << "ret = " << ret << endl;
}

//内联函数
//内联函数好处  和普通函数一样，不会有宏缺陷，会在适当的地方做类似宏替换，以空间换时间
//函数的声明和实现必须同时加 inline关键字，这个函数才成为内联函数的候选人
inline void func(int a, int b);
inline void func(int a, int b)
{
}

//成员函数的前面，都隐藏的加了inline关键字

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}