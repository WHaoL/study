#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、直接修改
void test01()
{
	int a = 10;
	printf("%d\n", a);
	a = 20;
	printf("%d\n", a);
}
//2、间接修改
void test02()
{
	int a = 10;
	int * p = &a;
	printf("a = %d\n", a);
	*p = 20;
	printf("a = %d\n", a);
}

//结构体修改
struct Person
{
	char a; //0 ~ 3
	int b;  //4 ~ 7
	char c; //8 ~ 11
	int d;  //12 ~ 15
};

void test03()
{
	struct Person p = { 'a', 10, 'b', 20 };
	printf("p的d属性的值为：%d\n", p.d);

	p.d = 100;
	printf("p的d属性的值为：%d\n", p.d);

	struct Person * pp = &p;
	pp->d = 1000;
	printf("p的d属性的值为：%d\n", p.d);
}

void test04()
{
	struct Person p = { 'a', 10, 'b', 20 };

	char * pp = &p;
	printf("sizeof struct Person  = %d\n", sizeof(struct Person));

	*(int *)(pp + 12) = 1000;
	printf("%d\n", pp);
	printf("%d\n", pp + 1);
	printf("p的d属性的值为：%d\n", *(int *)(pp + 12));


	printf("p的d属性的值为：%d\n",  *(int *)((int*)pp  + 3 ));
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}