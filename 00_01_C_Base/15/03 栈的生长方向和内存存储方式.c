#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、栈的生长方向
void test01()
{
	int a = 10;   // 栈底    高地址
	int b = 10;
	int c = 10;
	int d = 10;   // 栈顶    底地址

	printf("a的地址为:%d\n", &a);
	printf("b的地址为:%d\n", &b);
	printf("c的地址为:%d\n", &c);
	printf("d的地址为:%d\n", &d);
}

//2、内存存储方式
void test02()
{
	int a =  0x11223344;

	char * p = &a;

	printf("%x\n", *p);    //    44  低位字节数据  底地址

	printf("%x\n", *(p+1));//    33  高位字节数据  高地址

	printf("%x\n", *(p + 2));

	printf("%x\n", *(p + 3));
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}