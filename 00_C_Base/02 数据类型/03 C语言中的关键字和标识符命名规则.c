#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//关键字
//C语言中预先保留的单词，我们不可以用这些单词给变量 命名

void test01()
{
	//变量名 改为 int
	//int int = 10;
	//int extern = 10;
	//int void = 10;
	//int return = 10;
}


//标识符命名规则  ----  变量的起名规则
//1、标识符名称 不可以是关键字
//2、标识符 由字母、数字、下划线_ 组成 
//3、第一个字符  必须以字母 或 下划线 开头
//4、标识符中的字母 区分大小写
void test02()
{
	
	//int int = 10;  //error
	int abc = 10;
	int abc123 = 10;
	int abc_123 = 10;
	//int 123abc = 10;  //error
	int _123abc = 10;
	int aaa = 10;
	
	//printf("aaa = %d\n", AAA);//error 区分大小写


	//建议 给标识符命名的时候，最好做到见名知意的效果，提高代码的可读性
	int num1 = 10;
	int num2 = 10;
	int sum = num1 + num2;
	printf("%d\n", sum);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}