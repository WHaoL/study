#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//1、对const的变量取地址，会分配临时内存
void test01()
{
	const int m_a = 100;
	int * p = (int *)&m_a; // 创建临时temp，分配内存
}

//2、使用变量 来初始化const修饰的变量
void test02()
{
	int a = 100;
	const int m_a = a;

	int * p = (int *)&m_a;
	*p = 1000;
	cout << m_a << endl;
}

//3、对于自定义数据类型，分配内存
struct Person
{
	string name;
	int age;
};
void test03()
{
	const Person p; //放在栈上

	//p.age = 10;
	Person * pp = (Person *)&p;

	pp->name = "张三";
	pp->age = 18;

	cout << "姓名： " << p.name << " 年龄： " << p.age << endl;
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}