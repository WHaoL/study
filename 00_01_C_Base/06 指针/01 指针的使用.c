#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//指针的使用
void test01()
{
	int a = 10;
	//定义一个指针
	int* p;
	//建立关系
	p = &a;

	printf("&a = %d\n", &a);
	printf("p = %d\n", p);


	//指针的操作
	*p = 100;
	printf("a = %d\n", a);
	printf("*p = %d\n", *p);

	//注意：当使用指针时候，碰到 &*组合，可以从右向左依次抵消
	//*p == a ???  *&p  == &a     *p = *&a;   *p = a
}

//指针的大小
void test02()
{
	//在32位操作系统下  指针的大小是4个字节
	//在64位操作系统下  指针的大小是8个字节
	printf("sizeof int * = %d\n", sizeof(int *));
	printf("sizeof char * = %d\n", sizeof(char *));
	printf("sizeof float * = %d\n", sizeof(float *));
	printf("sizeof double * = %d\n", sizeof(double *));
}

//空指针
void test03()
{
	int * p = NULL; //NULL本质就是 0

	//访问空指针的存储内容 会报错
	//内存地址编号为 0 ~ 255之间的系统占用的内存，用户不可以访问
	//printf("%d\n", *p); //error 空指针不可以访问
}

//野指针
void test04()
{
	//利用指针变量p指向非法内存空间 0x1100
	int * p = 0x1100;

	//printf("%d\n", *p);
}

//注意事项：不要操作未初始化的指针变量
void test05()
{
	int * p; //也属于野指针
	//*p = 100; //vs 也好gcc也好 访问非法内存 都会报错
	//printf("%d\n", *p);  //error 非法访问内存
}

int main(){
	test05();



	system("pause");
	return EXIT_SUCCESS;
}