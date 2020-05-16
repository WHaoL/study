#define _CRT_SECURE_NO_WARNINGS  //防止 C4996错误 
#include<stdio.h>  //标准输入输出头文件   std  标准  i  input  输入  o output  输出
#include<string.h>  //字符串处理函数  strcpy  strcmp  strstr 
#include<stdlib.h>  //标准库头文件   malloc   free


//1、typedef使用
//用途：给类型起别名
//可以简化struct 关键字
//struct Person
//{
//	char name[64]; //姓名
//	int age; //年龄
//};
//typedef struct Person  MyPerson;


typedef struct Person
{
	char name[64]; //姓名
	int age; //年龄
}MyPerson;


void test01()
{
	struct Person p1;

	MyPerson p2;
}


//2、typedef区分数据类型
void test02()
{
	//char  *p1, p2;
	//语法 typedef  原名  别名
	typedef char * PCHAR;

	PCHAR p1, p2;


	char *p3, *p4;
}


//3、提高移植性
typedef int MYINT;
void test03()
{

	MYINT a = 100;


	MYINT b = 100;
}


//程序的入口 main函数
int main(){





	system("pause"); //阻塞 
	return EXIT_SUCCESS; //返回正常退出值
}