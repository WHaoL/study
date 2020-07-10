#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 字符串常量
void test01()
{
	// 双引号引起的内容 称为字符串常量
	// 双引号引起的内容中会带着字符串结束标志  \0
	printf("%s\n", "hello world"); 
	// 双引号会返回字符串的首字符的地址编号 
	// %s输出时 遇到\0 结束输出
	printf("sizeof = %d\n", sizeof("hello world")); // 12

	printf("%s\n", "hello\0world");
	printf("%s\n", "\0hello world");
}

// 字符串变量
void test02()
{
	char str[] = "hello world";

	printf("%s\n", str);
	printf("sizeof = %d\n", sizeof(str)); //12

	str[0] = 'x';
	printf("%s\n", str);

	//后续课程中 会对字符串进行更深入操作
}

//单引号和双引号区别
void test03()
{
	char a1 = 'a';
	char a2[] = "a"; // a \0

	//前者是字符  后者是字符串

	//前者保存是ASCII码值，后者取出字符串首字母地址进行保存

	//前者 占用1个字节  后者 占用 2个字节

}


int main(){

	test02();


	system("pause");
	return EXIT_SUCCESS;
}