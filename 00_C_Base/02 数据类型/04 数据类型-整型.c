#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//整型
// short  int  long  longlong 

void test01()
{
	short num1 =  32768; // (-2^15 ~ 2^15-1)    -32768 ~ 32767

	int num2 = 32768;

	long num3 = 10;

	long long num4 = 10;

	printf("num1 = %hd\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %ld\n", num3);
	printf("num4 = %lld\n", num4);
}

//有符号和无符号 常量
void test02()
{
	printf("%d\n", 10); //有符号整型int  用%d进行输出

	printf("%u\n", 10U); //无符号整型int  用%u进行输出

	printf("%ld\n", 10L); //有符号整型 long  用%ld进行输出

	printf("%lu\n", 10UL); // 无符号整型long  用%lu进行输出
}

//有符号和无符号 变量
void test03()
{
	signed int a = 10; //默认是有符号的变量 ，在前面隐藏的加了关键字 signed
	printf("%d\n", a);

	unsigned int a2 = 10; //无符号整型变量 unsigned进行修饰
	printf("%u\n", a2);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}