#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//typedef的使用

//1、typedef关键字   原名   别名；
typedef int MYINT;

void test01()
{
	int a = 10;
	MYINT b = 20;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}


//2、可以给结构体起别名
typedef struct itcastStudentInfo
{
	char name[64];
	int age;
}student;

void test02()
{
	struct itcastStudentInfo s1 = { "Tom", 19 };

	student s2 = { "Jerry", 20 };
}


//3、结构体指针类型
typedef struct itcastStudentInfo2
{
	char name[64];
	int age;
}stu,*pStu;  // stu  -> struct itcastStudentInfo2   pStu -> struct itcastStudentInfo2 *  ====  stu *

void test03()
{
	stu s = { "aaa", 10 };

	pStu p = &s;

	printf("姓名:%s  年龄:%d\n", p->name, p->age);

}

int main(){

	//test01();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}