#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int a = 10;
	printf("十进制输出： %d\n", a);
	printf("八进制输出： %#o\n", a);
	printf("十六进制输出： %#x\n", a);
	printf("十六进制输出： %#X\n", a);
}

void test02()
{
	int a = 123;   //十进制
	int b = 0123;  //八进制
	int c = 0xabc; //十六进制数字

	printf("%d\n", a);
	printf("%#o\n", b);
	printf("%#x\n", c);
}
//额外扩展
void test03()
{
	//控制终端中显示的宽度 ,默认数字是右对齐
	printf("##%5d##\n", 123);
	printf("##%2d##\n", 123);

	printf("##%-5d##\n", 123); //数字左对齐


	printf("##%05d##\n", 123); //用0填充空格位置

	//注意： 0 和 - 不可以共存的   %-05d    0不起效果
	printf("##%-05d##\n", 123);
}
int main(){

	//test03();
	int k = -8567; printf("|%06d|\n", k);
	system("pause");
	return EXIT_SUCCESS;
}