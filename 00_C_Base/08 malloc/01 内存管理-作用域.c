#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1、普通局部变量
//定义的形式：在{}中定义的变量，称为局部变量
//作用范围：离最近的{}之间可以使用
//生命周期：最近的{}结束后，这个变量被释放
//注意事项：不初始化普通局部变量，初始值是随机的
void test01()
{
	{
		int a = 10;
		printf("a = %d\n", a);
	}
	
	int a2 = 100;
	{
		//不同作用域下的局部变量，发生同名时候，优先使用最近的同名变量，就近原则
		int a2 = 200;
		printf("{}里 a2 = %d\n", a2);
	}

	printf("{}外 a2 = %d\n", a2);
}

//普通全局变量
//定义的形式：在函数体外，定义的变量，称为全局变量
//作用范围：当前的源文件中，或者其他源文件中也可以使用(需要加extern关键字声明)
//生命周期：整个程序执行完过后，才释放掉
//注意事项：不初始化全局变量，初始值是0

int g_a; //默认初始值为 0 
void test02()
{
	printf("g_a = %d\n", g_a);

	extern int g_b; //告诉编译器 在其他文件中有g_b,下面使用时候先不要报错
	printf("g_b = %d\n", g_b);
}


//静态局部变量 
//定义的形式：在{}中定义的变量，用static 修饰 ，称为静态局部变量
//作用范围：离最近的{}之间可以使用
//生命周期：整个程序执行完过后，才释放掉
//注意事项：不初始化静态局部变量，初始值是0
//			静态局部变量 只初始化一次


void func()
{
	static int num = 10;	

	num++;

	printf("num =%d\n", num);
}

void test03()
{
	//static int a; //不初始化 初始值为 0
	//printf("a = %d\n", a);
	func(); //11 
	func(); //12
	func(); //13
	func(); //14

}


//静态全局变量
//定义的形式：在函数体外定义的变量，用static 修饰 ，称为静态全局变量
//作用范围：从定义开始后，在当前文件中可以使用
//生命周期：整个程序执行完过后，才释放掉
//注意事项：不初始化静态全局变量，初始值是0
//			静态全局变量 只初始化一次

static int g_s_a;

void test04()
{
	printf("g_s_a = %d\n", g_s_a);
}


//全局函数  静态函数
//全局函数：在C语言下默认的都是全局函数
//静态函数：用static关键字修饰后的函数 ，称为静态函数
//			只能在当前文件中使用

void test05()
{
	extern void func1();
	func1();

	//extern void func2();
	//func2(); //error func2中是一个静态函数，不可以调用
}


int main(){

	test04();



	system("pause");
	return EXIT_SUCCESS;
}