#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//算术运算符  + - * /
void test01()
{
	int a = 10;
	int b = 3;
	

	printf("a + b = %d\n", a + b); //13
	printf("a - b = %d\n", a - b); //7
	printf("a * b = %d\n", a * b); //30
	printf("a / b = %d\n", a / b); //3  两个正数相除  结果也是正数，小数部分舍弃掉


	int a2 = 10;
	int b2 = 20;
	printf("a2 / b2 = %d\n", a2 / b2); // 0

	int a3 = 10;
	int b3 = 0;
	//printf("a3 / b3 = %d\n", a3 / b3);//error 除数不可以为0

	//两个小数之间 是可以做除法运算的
	double d1 = 0.5;
	double d2 = 0.25;
	printf("d1 / d2 = %lf\n", d1 / d2);
}

//取模  取余 运算
void test02()
{
	int a1 = 10;
	int b1 = 3;

	printf("10 %% 3 = %d\n", a1 % b1);

	int a2 = 10;
	int b2 = 20;

	printf("a2 %% b2 = %d\n", a2 % b2); // 10

	int a3 = 10;
	int b3 = 0;
	//printf("a3 %% b3 = %d\n", a3 % b3);  //error

	double d1 = 5.3;
	double d2 = 1.1;
	//对于小数而言，是不可以取余数
	//printf("d1 %% d2 = %lf\n", d1 %d2);//error 
}

void test03()
{
	int num = 5678;

	printf("千位是 = %d\n", num / 1000); //1234 / 1000 = 1
	printf("百位是 = %d\n", num % 1000 / 100); // 1234 % 1000 = 234  / 100 = 2
	printf("十位是 = %d\n", num %100/10); // 1234 % 100 = 34  / 10  = 3
	printf("个位是 = %d\n", num % 10); // 1234 % 10 = 4
}

void test04()
{
	//自增 递增
	// ++

	////后置递增
	//int a = 10;
	//a++; // a = a + 1;
	//printf("a = %d\n", a);

	////前置递增
	//int b = 10;
	//++b; // b = b+1;
	//printf("b = %d\n", b);

	//作为独立语句，前置和后置没有区别
	//当进行混合运算时，才有区别


	////前置++  先对变量 进行 ++ 再 计算表达式
	//int a3 = 10;
	//int b3 = ++a3 * 10; // a3 = a3 + 1   b3 = a3 * 10
	//printf("a3 = %d\n", a3); //11
	//printf("b3 = %d\n", b3); //110 


	////后置++ 先计算表达式   再对变量进行++运算
	//int a4 = 10;
	//int b4 = a4++ * 10; 
	//printf("a4 = %d\n", a4); //11
	//printf("b4 = %d\n", b4); //100  

	//建议：不要在一个表达式中 既有前置又有后置  可读性太低
	int num1 = 10;
	int num2 = 10;

	num2 = ++num1* num1++ - ++num1;

	printf("num1 = %d\n", num1); // 13    
	printf("num2 = %d\n", num2); // 132


}

int main(){

	test04();


	system("pause");
	return EXIT_SUCCESS;
}