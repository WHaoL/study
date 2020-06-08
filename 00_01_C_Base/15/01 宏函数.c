#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//用函数的形式写宏 ，宏函数
//宏函数，加一些括号保证运算的完整性
//宏函数使用场景：通过将一些比较频繁短小的函数，写成宏函数
//优点：可以省去普通函数的入栈、出栈的时间上的开销     以空间换时间
#define MYADD(x,y) ((x)+(y))

int myAdd(int x,int y)
{
	return x + y;
}

void test01()
{
	int a = 10;
	int b = 20;

	printf("a + b = %d\n", MYADD(a, b)  * 20); // ((10) + (20)) * 20

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}