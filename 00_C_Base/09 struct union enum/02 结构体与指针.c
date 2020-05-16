#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int id; //不可以给初始值  int id = 0; 这个是错误的写法
	char name[64];
	float score;
};

void test01()
{
	struct student s1 = { 1, "Tom", 100 };

	struct student * p = &s1;

	printf("id = %d name = %s score = %.2f\n", p->id,p->name,p->score);
	printf("id = %d name = %s score = %.2f\n", s1.id, s1.name, s1.score);

	printf("id = %d name = %s score = %.2f\n", (&s1)->id, (&s1)->name, (&s1)->score);
	printf("id = %d name = %s score = %.2f\n", (*p).id, (*p).name, (*p).score);

}

//指针 通过键盘获取数据
void test02()
{
	struct student s1;
	//清空
	memset(&s1, 0, sizeof(struct student));

	struct student* p = &s1;

	scanf("%d %s %f", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	
}

//结构体创建在堆区
void test03()
{
	struct student * p = NULL;

	p = malloc(sizeof(struct student));

	//清空
	memset(p, 0, sizeof(struct student));

	printf("请输入学号，姓名，分数\n");
	scanf("%d %s %f", &p->id, p->name, &p->score);

	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//结构体数组 创建在堆区
void test04()
{
	int num = 0;
	printf("请输入学生个数\n");
	scanf("%d", &num);

	struct student * arr = malloc(sizeof(struct student) * num);

	//清空
	memset(arr, 0, sizeof(struct student)*num);

	//从键盘获取用户输入
	for (int i = 0; i < num; i++)
	{
		printf("请给第 %d 个学生输入信息", i + 1);
		//scanf("%d %s %f", &arr[i].id , arr[i].name, &arr[i].score );
		scanf("%d %s %f",  &(arr+i)->id ,  (arr+i)->name , &(arr+i)->score  );
	}

	for (int i = 0; i < num; i++)
	{
		printf("id = %d name = %s score = %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}

	//释放数组
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}


//结构体指针做函数参数
void setStudent(struct student *p)
{
	scanf("%d %s %f", &p->id,  p->name, &p->score);
}

void test05()
{
	struct student s1;
	memset(&s1, 0, sizeof(struct student));

	setStudent(&s1);
	printf("id = %d name = %s score = %.2f\n", s1.id, s1.name, s1.score);
}


//结构体数组做函数参数 
void setArray(struct student* arr, int num)
{
	printf("请输入%d个学生的信息\n",num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %s %f", &arr[i].id, arr[i].name, &arr[i].score);
	}
}

void printArray(struct student* arr, int num)
{
	for (int i = 0; i < num;i++)
	{
		printf("id = %d name = %s score = %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

void test06()
{
	struct student arr[2];

	memset(arr, 0, sizeof(arr));

	setArray(arr, 2);

	printArray(arr, 2);
}

int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	
	system("pause");
	return EXIT_SUCCESS;
}