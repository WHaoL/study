#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <stddef.h> //offsetof的头文件  std 标准   def  宏  

//指针步长的意义
//1、指针步长： +1之后 跳跃字节数不同
void test01()
{
	char *p = NULL;
	printf("%d\n", p);
	printf("%d\n", p+1);

	int *p2 = NULL;
	printf("%d\n", p2);
	printf("%d\n", p2 + 1);
}

//2、解引用的使用，取出的字节数不同
void test02()
{
	char buf[1024] = { 0 };

	int a = 1000;

	memcpy(buf+1, &a, sizeof(int));

	char * p = buf;

	printf("%d\n", *(int*)(p + 1));
}

//自定义数据类型 练习
struct Person
{
	char a;   // 0 ~ 3
	int b;    // 4 ~ 7
	char buf[64]; // 8 ~ 71 
	int d; // 72 ~ 75
};


void test03()
{
	struct Person p = { 'a', 10, "hello world", 1000 };

	//需求1 ： 求d属性 相对于struct Person的偏移量
	//语法 offsetof( 结构体， 成员 )
	printf("d的偏移量：%d\n", offsetof(struct Person, d));


	//需求2 ：通过偏移量 获取到 d的属性值
	printf("d的值为:%d\n", *(int *)((char*)&p + offsetof(struct Person, d)));
}

int main(){
	test03();


	system("pause");
	return EXIT_SUCCESS;
}