#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sizeof 统计一个类型  或者一个变量 占用的内存空间大小
void test01()
{
	printf("short占用内存空间为：%d\n", sizeof(short)); //2

	int a = 10;
	printf("a占用内存空间为: %d\n", sizeof(a)); //4
	printf("int 占用内存空间为: %d\n", sizeof(int)); //4

	printf("long 占用内存空间为: %d\n", sizeof(long)); //4

	printf("long long 占用内存空间为: %d\n", sizeof(long long)); // 8
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}