#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1、值传递
// 通过一个函数实现两个整型数字交换的函数
void mySwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	printf("mySwap中的a = %d\n", a); // 20
	printf("mySwap中的b = %d\n", b); // 10
}

void test01()
{
	int a = 10;
	int b = 20;

	//值传递的 形参是改变不了实参的
	mySwap(a, b);

	printf("test01中的a = %d\n", a);
	printf("test01中的b = %d\n", b); 

}


//2、地址传递
void mySwap2(int * p1 , int * p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	printf("mySwap2中的*p1 = %d\n", *p1);
	printf("mySwap2中的*p2 = %d\n", *p2);
}

void test02()
{
	int a = 10;
	int b = 20;
	//地址传递的形参 可以修改实参
	mySwap2(&a,&b);

	printf("test02中的a = %d\n", a);
	printf("test02中的b = %d\n", b);
}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}