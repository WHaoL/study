#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、全局变量检测增强
int a;
//int a = 10;  error重定义


//2、函数增强  C++返回值检测增强，形参检测增强,传参个数检测增强
int getRectS(int w, int h)
{
	return w * h;
}

void test01()
{
	getRectS(10, 10);
}

//3、类型转换检测增强
void test02()
{
	char *  p = (char *)malloc(64);
}


//4、struct 增强
//C++语言下 结构体中可以有函数
struct Person
{
	int age;
	void showAge(){ cout << age << endl; };
};
void test03()
{
	Person p1;  //可以简化struct关键字
	p1.age = 18;
	p1.showAge();
}

//5、bool类型 代表真假
bool flag = true; //true 代表真 1   false 代表假 0
void test04()
{
	cout << "sizeof bool = " << sizeof(bool) << endl; // 1

	flag = false; 
	//flag = 100;
	cout << flag << endl;
}


//6、三目运算符增强
void test05()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	(a < b ? a : b )= 100; //返回的是变量的引用

	printf("a = %d\n", a); //100
	printf("b = %d\n", b); //20
}


//7、const增强  受到常量区保护
const int m_a = 100;
void test06()
{
	//m_a = 200;
	//int * p = (int *)&m_a;
	//*p = 1000;

	//C++中放在 符号表
	const int m_b = 100;
	//m_b = 200;
	int * p =(int*)&m_b;
	*p = 1000;
	cout << "m_b = " << m_b << endl;

	int arr[m_b] = {0};
}

int main(){
	test06();


	system("pause");
	return EXIT_SUCCESS;
}