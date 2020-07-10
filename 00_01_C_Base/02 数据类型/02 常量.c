#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DAY 7

//常量 在程序运行期间 不可以改变的量
void test01()
{
	//一共有5种表现的形式

	//1、数值常量(整数型常量（整数） 、实数型常量（小数）)  
	// 100 200 300  3.14   1.1 2.2 3.3
	//100 = 200; //error 常量是不可以修改的！

	//2、字符常量  'a' 'b' 'c' '\n' '\t'
	//'a' = 'b'; error

	//3、字符串常量  "hello world"
	//"hello world" = "aaaa"; error

	//4、符号常量  （宏常量）
	//利用 #define 
	printf("一周一共有%d天\n", DAY);
	//DAY = 14; error

	//5、const 修饰的变量 
	const int month = 12;
	printf("一年一共有%d月\n", month);
	//month = 24;  error  此时是一个常量了 不可以修改
	
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}