#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  结构体定义
//  struct student是一个数据类型   类似  int  double  char
//  下面要用{}包含类型中的成员 {}后面要加上分号‘;’
//  定义结构体类型只是一个模具，没有占用具体内存空间
struct student
{
	int id;			//学号
	char name[64];  //姓名
	float score;	//分数
	int age;		//年龄
};

void test01()
{
	//通过结构体类型，创建结构体变量
	//给结构体变量赋值的时候要按照顺序赋值
	struct student s1 = { 1, "Tom", 99.9, 18 };

	//通过 '.' 符号 可以找到具体的成员
	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);

}


//在定义结构体时候，顺便创建结构体变量
struct student2
{
	int id;			//学号
	char name[64];  //姓名
	float score;	//分数
	int age;		//年龄
}s;  //s代表 通过struct sutdent2创建的结构体变量
void test02()
{
	s.id = 2;
	//s.name = "Jerry";  //error
	strcpy(s.name, "Jerry");
	s.score = 80;
	s.age = 19;

	
	printf("id = %d\n", s.id);
	printf("name = %s\n", s.name);
	printf("score = %f\n", s.score);
	printf("age = %d\n", s.age);
}


//从键盘获取成员输入
void test03()
{
	struct student s1;// = { 3, "Tom", 66.6, 20 };

	//通过键盘获取输入
	printf("请给学号赋值\n");
	scanf("%d", &s1.id);

	printf("请给姓名赋值\n");
	scanf("%s", s1.name);

	printf("请给分数赋值\n");
	scanf("%f", &s1.score);

	printf("请给年龄赋值\n");
	scanf("%d", &s1.age);

	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);

}


//结构体成员赋值
void test04()
{
	struct student s1;
	struct student s2 = {1,"Tom",99,18};


	//方法1  逐个成员赋值
	//s1.id = s2.id;
	//strcpy(s1.name, s2.name);
	//s1.score = s2.score;
	//s1.age = s2.age;

	//方法2 如果是两个类型相同的结构体变量，可以直接=赋值  推荐
	//s1 = s2;

	//方法3 利用内存操作函数 memcpy
	memcpy(&s1, &s2, sizeof(struct student));

	
	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);
}

//交换两个结构体变量
void test05()
{
	struct student s1 = {10,"Jerry",10, 20};
	struct student s2 = { 1, "Tom", 99, 18 };

	//创建临时结构体变量，进行交换
	struct student temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

	printf("s1 --- id = %d  name = %s score = %f age = %d\n", s1.id , s1.name,s1.score,s1.age);
	printf("s2 --- id = %d  name = %s score = %f age = %d\n", s2.id, s2.name, s2.score, s2.age);
}

//结构体数组
void test06()
{
	struct student arr[5] =
	{
		{ 1, "刘备", 100, 30 },
		{ 2, "张飞", 90, 31 },
		{ 3, "关羽", 80, 32 },
		{ 4, "赵云", 88, 34 },
		{ 5, "吕布", 96, 33 }  //最后一行的 ',' 可以省略
	};
	int num = sizeof(arr) / sizeof(struct student);
	for (int i = 0; i < num;i++)
	{
		printf("id = %d  name = %s score = %.2f age = %d\n", arr[i].id, arr[i].name, arr[i].score, arr[i].age);
	}

	//求年龄的平均值
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i].age;
	}
	printf("年龄平均值为:%d\n", sum / num);
}

//结构体嵌套结构体
struct stu
{
	int id;
	int age;
};

struct Teacher
{
	int id;
	struct stu s; //老师结构体中有个学生的成员
};
void test07()
{
	struct Teacher t1 = { 1000, { 100, 18 } };
	struct Teacher t2 = { 1001, 101, 19 };

	printf("t1  id = %d  stu id = %d  age = %d\n", t1.id, t1.s.id, t1.s.age);
	printf("t2  id = %d  stu id = %d  age = %d\n", t2.id, t2.s.id, t2.s.age);
}

int main(){
	test07();


	system("pause");
	return EXIT_SUCCESS;
}