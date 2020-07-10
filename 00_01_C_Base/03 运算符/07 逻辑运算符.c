#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//逻辑非  !
void test01()
{
	int a = 10;
	printf("!a = %d\n", !a); //0
	printf("!!a = %d\n", !!a); //1

	printf("%d\n", !100); // 0
	printf("%d\n", !!100); // 1
	printf("%d\n", !-100); // 0

	//非零都是真！！！
}

//逻辑与
void test02()
{
	//同真为真  一假为假
	int a = 10;
	int b = 20;
	printf(" a && b = %d\n", a && b); //1

	a = 10;
	b = 0;
	printf(" a && b = %d\n", a && b); //0


	a = 0;
	b = 0;
	printf(" a && b = %d\n", a && b); //0


	//注意：只有表达式1  为真 ，才会判断表达式2      短路特性
	4 < 3 && printf("hello1\n");

	4 > 3 && printf("hello2\n");
}

//逻辑或
void test03()
{
	// 同假为假  一真为真 ||

	int a = 10;
	int b = 10;
	printf("a || b = %d\n", a || b); // 1

	a = 0;
	b = 10;
	printf("a || b = %d\n", a || b); // 1

	a = 0;
	b = 0;
	printf("a || b = %d\n", a || b); // 0

	//注意：只有表达式1为假  才判断表达式2   短路特性
	4 < 3 || printf("hello1\n"); //执行hello1
	4 > 3 || printf("hello2\n"); //不执行 hello2
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}