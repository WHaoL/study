#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、const 修饰的 *      称为常量指针
void test01()
{
	int a = 10;
	const int  *p = &a; //*p只读  p可读可写   等价于 int const  *p = &a;
	
	//*p = 100; //error 指针指向的值 不可以修改

	int b = 20;
	p = &b;  //success 指针的指向可以修改
}

//2、const 修饰的 p   称为指针常量
void test02()
{
	int a = 10;
	int *  const p = &a;//*p可读可写   p只读

	*p = 20; //success  指针指向的值 可以修改的

	int b = 20;

	//p = &b; // error  指针的指向不可以修改

}


//3、const 修饰 * 和 p
void test03()
{
	int a = 10;
	const int * const p = &a; //等价于 int const * const p = &a;

	//*p = 100;  error 指针指向的值不可以改

	int b = 20;
	//p = &b;  error指针的指向不可以改

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}