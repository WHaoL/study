#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union data
{
	int a;
	char b;
	short c;
};

void test01()
{
	printf("sizeof data = %d\n", sizeof(union data)); //4 字节，在联合体中最大成员的类型就是联合体的占用空间

	union data d;
	d.a = 10;
	d.b = 20;
	d.c = 30;
	//只有最后一次赋值生效的
	printf("a + b + c = %d\n", d.a + d.b + d.c); // 30 + 30 + 30 = 90
}

void test02()
{
	union  data d;
	d.a = 0x01020304; //4字节

	printf("data.a = %#x\n", d.a); // 0x1020304

	printf("data.b = %#x\n", d.b); // 0x4

	printf("data.c = %#x\n", d.c); // 0x304
}


void test03()
{
	union data d;

	d.a = 0x01020304;
	d.b = 0x01;
	d.c = 0x0102;

	printf("d.a + d.b + d.c = %#x\n", d.a + d.b + d.c); // 0x1020206 

}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}