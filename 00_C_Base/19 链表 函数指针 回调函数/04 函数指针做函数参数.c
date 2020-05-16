#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//封装一个函数，可以打印任意数据类型的数据
void printAllType(void * data , void(*myPrint)(void *))
{
	//printf("%lf\n", *(int *)data);

	//打印需要交还给用户去处理
	myPrint(data);
}

//回调函数，开始是不调用的，触发特定场景才去调用
void printInt(void * data)
{
	int * num = data;
	printf("%d\n", *num);
}

void test01()
{
	int a = 10;

	printAllType(&a, printInt);

	//double b = 3.14;

	//printAllType(&b);
}

struct Person
{
	char name[64];
	int age;
};
//用户提供一个回调函数
void printPerson(void *data)
{
	struct Person * p = data;
	printf("姓名:%s  年龄:%d\n", p->name, p->age);
}
void test02()
{
	struct Person p1 = { "aaa", 10 };

	printAllType(&p1, printPerson);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}