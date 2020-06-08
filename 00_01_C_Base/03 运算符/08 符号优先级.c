#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//符号的优先级是在混合运算中才讨论 
//表中优先级号越小，优先级越高
//同一优先级中，看结合性
void test01()
{
	int a = 10;

	//自增自减运算符  优先级高于 * /
	printf("%d\n", ++a * 10); // 110
}

void test02()
{
	//比较运算符 高于 赋值运算符
	int a = 10;
	printf("%d\n", a = 23 > 24); // 0
}

void test03()
{
	// 逻辑与  高于 逻辑或
	printf("%d\n", 1 || 1 && 0); //1

}

void test04()
{
	int a = 10;
	//同一个级别 赋值运算 从右向左结合
	//a += a -= a *= a /= 3;
	
	printf("a = %d\n", a); //0
}

// , 优先级最低的
void test05()
{
	int num = 0;
	num = 1, 2, 3, 4;  //先赋值
	printf("num = %d\n", num); //1 

	num = (1, 2, 3, 4); //1 2 3 4 先看结合性  让4 赋值给num
	printf("num = %d\n", num); //4  
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}