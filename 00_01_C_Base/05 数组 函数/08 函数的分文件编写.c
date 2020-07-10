#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "test.h" //如果用自定义的函数，需要将头文件包含到当前文件中

//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}

void test01()
{
	int a = 10;
	int b = 10;
	printf("a + b = %d\n", add(a, b));
	printf("a - b = %d\n", sub(a, b));

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}