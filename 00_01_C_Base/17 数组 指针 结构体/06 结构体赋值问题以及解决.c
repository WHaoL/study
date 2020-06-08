#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char name[64];
	int age;
};

void test01()
{
	struct Person p1 = { "Tom", 18 };

	struct Person p2 = { "Jerry", 20 };

	p1 = p2;

	printf("p1的姓名为:%s 年龄为:%d\n", p1.name, p1.age);
	printf("p2的姓名为:%s 年龄为:%d\n", p2.name, p2.age);
}



struct Person2
{
	char * name;
	int age;
};

void test02()
{
	struct Person2 p1;
	p1.name = malloc(sizeof(char)* 64);
	p1.age = 18;
	strcpy(p1.name, "Tom");

	struct Person2 p2;
	p2.name = malloc(sizeof(char)* 128);
	p2.age = 20;
	strcpy(p2.name, "Jerry");

	//p1 = p2;
	////////////////////////////////////
	//手动赋值

	p1.age = p2.age;

	//先释放原有内存
	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}

	p1.name = malloc( strlen(p2.name)+ 1);
	strcpy(p1.name, p2.name);



	////////////////////////////////////
	printf("p1的姓名为:%s 年龄为:%d\n", p1.name, p1.age);
	printf("p2的姓名为:%s 年龄为:%d\n", p2.name, p2.age);

	//释放堆区
	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}

	if (p2.name != NULL)
	{
		free(p2.name);
		p2.name = NULL;
	}
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}