#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void b()
{
	int aaa = 10;//在 b中创建的栈上变量，main函数 和 a 中无法使用
}

void a()
{
	int aa = 10; //在a中创建的栈上变量，main函数中无法使用，b中 可以使用

	b();
}

int main(){

	//int aa = 10;  在主函数中创建的栈上变量，在a、b中都可以使用

	a();

	system("pause");
	return EXIT_SUCCESS;
}