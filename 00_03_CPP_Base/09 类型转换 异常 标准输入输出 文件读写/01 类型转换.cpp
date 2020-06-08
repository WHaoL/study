#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、静态转换
//内置数据类型转换
void test01()
{
	char a = 'a';
	//语法： static_cast<目标类型>(原变量/对象)
	double d = static_cast<double>(a);

	cout << d << endl;
}

//父子之间指针或者引用
class Base{};
class Son :public Base{};
class Other{};
void test02()
{
	Base * base = NULL;
	Son * son = NULL;

	//将base转 Son *      父转子   不安全  向下类型转换

	Son * son2 = static_cast<Son *>(base);


	//将son 转为 Base *   子转父   安全   向上类型转换
	Base * base2 = static_cast<Base *>(son);

	//将base 转为Other*
	//Other * other = static_cast<Other*>(base); //error 不是父子类 转换无效
}


//2、动态转换
void test03()
{
	char a = 'a';

	//内置数据类型之间不允许转换
	//double d = dynamic_cast<double>(a);
}

class Base2{ public: virtual void func(){} };
class Son2 :public Base2{ public: virtual void func(){} };
class Other2{};

void test04()
{
	Base2 * base = NULL;

	Son2 * son = NULL;

	//将base 转为Son2 *   父转子  不安全 向下类型转换
	//Son2 * son2 = dynamic_cast<Son2*>(base);  error不安全

	//将son  转为 Base2 *   子转父 安全  向上类型转换
	//Base2 * base2 = dynamic_cast<Base2 *>(son);

	//如果发生多态，转换总是安全的
	Base2 * base3 = new Son2;
	//将base3 转为 Son2*
	Son2 * son3 = dynamic_cast<Son2*>(base3);

	//将base3 转为 Other *
	//Other2 * other = dynamic_cast<Other2 *>(base3);  没有关系的两个类之间 不应该转换
}


//常量转换
void test05()
{
	//指针之间
	int * p = NULL;

	const int * pp = const_cast<const int *>(p);

	int * ppp= const_cast<int *>(pp);


	//引用之间
	int num = 10;
	int &ref = num;

	const int & ref2 = const_cast<const int &>(ref);

	int & ref3 = const_cast<int &>(ref2);

	//const_cast只能用于指针或引用之间转换
	const int a = 10;
	//int b = const_cast<int>(a); //error 
}

//重新解释转换  不推荐使用
void test06()
{
	int a = 10;
	int * p  = reinterpret_cast<int *>(a);

	//将base转Other*
	Base * base = NULL;

	Other * other = reinterpret_cast<Other *>(base);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}