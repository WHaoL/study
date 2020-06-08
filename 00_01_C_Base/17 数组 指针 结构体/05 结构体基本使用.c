#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义方式1 
typedef struct Person1
{
	char name[64];
	int age;  //定义结构体时候，不要给成员赋值
}myPerson;

void test01()
{
	myPerson p1;
}

//定义方式2 
struct Person2
{
	char name[64];
	int age;  //定义结构体时候，不要给成员赋值
}myPerson2 = {"aaa" , 10};
void test02()
{
	printf("%s  %d\n", myPerson2.name, myPerson2.age);
}

//定义方式3 匿名
struct
{
	char name[64];
	int age;  //定义结构体时候，不要给成员赋值
}myPerson3 = { "bbb", 20 };


struct Person
{
	char name[64];
	int age;
};

void test03()
{
	//将结构体创建在栈上
	struct Person p1 = { "aaa", 100 };

	printf("姓名:%s 年龄:%d\n", p1.name, p1.age);

	//将结构体创建在堆区
	struct Person * p2 = malloc(sizeof(struct Person));
	p2->age = 18;
	strcpy(p2->name, "bbb");
	printf("姓名:%s 年龄:%d\n", p2->name, p2->age);
	free(p2);
	p2 = NULL;
}


void printPerson(struct Person arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("姓名:%s 年龄:%d\n", arr[i].name, arr[i].age);
	}
}
void test04()
{
	//结构体数组分配在栈上
	struct Person pArray[] = 
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(pArray) / sizeof(struct Person);
	printPerson(pArray, len);

	//结构体数组 分配在堆区
	struct Person * pArray2 = malloc(sizeof(struct Person) * 4);
	for (int i = 0; i < 4;i++)
	{
		pArray2[i].age = i + 10;

		sprintf(pArray2[i].name, "name_%d", i + 1);
	}
	printPerson(pArray2, 4);

	if (pArray2 != NULL)
	{
		free(pArray2);
		pArray2 = NULL;
	}
}

int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}