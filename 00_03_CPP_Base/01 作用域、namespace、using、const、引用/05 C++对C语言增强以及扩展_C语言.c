#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、全局变量检测增强
int a;
int a = 10;


//2、函数增强  C语言下可以不写返回值类型，形参不写数据类型，参数个数可以不符
getRectS( w,  h)
{
	return w * h;
}

void test01()
{
	getRectS(10, 10, 10);
}

//3、类型转换检测增强
void test02()
{
	char *  p = malloc(64);
}


//4、struct 增强
//C语言下 结构体中不可以有函数
struct Person
{
	int age;
	//void showAge(){};
};

void test03()
{
	struct Person p1; //必须要加struct 关键字
}

//5、bool类型 代表真假
//bool flag = true;


//6、三目运算符增强
void test05()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	//a > b ? a : b = 100; //C返回的结果是值

	*(a > b ? &a : &b) = 100;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}

//7、const增强

//全局const修饰的变量
const int m_a = 100; //放在常量区，受到保护
void test06()
{
	//m_a = 200;
	//int * p = &m_a;
	//*p = 1000;

	//局部const修饰的变量  放在栈上
	const int m_b = 100;
	//m_b = 200;
	int * p = &m_b;
	*p = 1000;
	printf("m_b = %d\n", m_b);

	//伪常量  不可以初始化数组
	//int arr[m_b];
}

int main(){

	test06();

	system("pause");
	return EXIT_SUCCESS;
}