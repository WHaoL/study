#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//赋值 运算  将=右边的值   赋给=左边
	int a = 10;
	a = 100;
	int b = 20;
	b = a;
	//左值    能够在=左边的值 成为左值
	//右值    只能在=右边的值 成为右值


	// += 
	a = 10;
	a += 2; // a = a + 2;
	printf("a = %d\n", a);  // 12
	// -=
	a = 10;
	a -= 2; // a = a - 2;
	printf("a = %d\n", a);   //8
	// *=
	a = 10;
	a *= 2; // a = a * 2;
	printf("a = %d\n", a);  // 20
	// /=
	a = 10;
	a /= 2; // a = a / 2;
	printf("a = %d\n", a);  // 5
	// %=
	a = 10;
	a %= 2; // a = a % 2;
	printf("a = %d\n", a);  // 0
}

void test02()
{
	//注意事项：在做+=  -= *=....中  =右边的表达式要看成一个整体
	int num = 10;
	num *= 3 + 5;  // num = num * (3 + 5)
	printf("num = %d\n", num); // 80

}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}