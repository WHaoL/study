#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//分类 ： 自动类型转换（隐式类型转换）  强制类型转换

//1 隐式类型转换
void test01()
{
	//int和double运算，先将int隐式转为double
	printf("%d\n", sizeof(5 / 2.0));
}

//大类型 转 小类型 容易溢出
void test02()
{
	int a = 353;
	//原码 256  64  32  1
	//0000 0001 0110 0001

	//char 补码  = 原码
	//0110 0001 = 64 + 32  + 1 = 97 
	char ch = a;

	printf("%c\n", ch);
}

//char 和short由于空间比较小，容易溢出，在运算时，通常转为 int型
void test03()
{
	char a = 10;
	short b = 10;

	printf("%d\n", sizeof(a + a)); //4
	printf("%d\n", sizeof(b + b)); //4
	printf("%d\n", sizeof(a + b)); //4
}

//2 强制类型转换
void test04()
{
	float f = 3.14f;

	int num = 0;

	num = (int)f; //强制类型转换，只是临时改变f的值

	printf("num = %d\n", num);
	printf("f = %f\n", f);
}

//注意：强制位置 很重要
void test05()
{
	float price = 1.6f; //黄瓜 
	int num = 2;

	int sum = num * (int)price;
	printf("sum = %d\n", sum); // 2

	sum = (int)(num *price);
	printf("sum = %d\n", sum); // 3

}

int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}