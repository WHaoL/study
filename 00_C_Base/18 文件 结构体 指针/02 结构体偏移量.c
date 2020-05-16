#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>

struct Teacher
{
	char a; //0~3
	int b;  //4~7 
};

void test01()
{
	struct Teacher t1;
	struct Teacher *p = &t1;

	printf("b的偏移为：%d\n", (int)&(p->b) - (int)p);

	printf("b的偏移为：%d\n",offsetof(struct Teacher,b) );
}

//通过偏移量获取数据
void test02()
{
	struct Teacher t1 = {'a' , 10};

	printf("b的值为：%d\n", *(int*)((char *)&t1 + offsetof(struct Teacher, b)));
	printf("b的值为：%d\n", *(int*)((int *)&t1 + 1 ));
}

//结构体嵌套结构体
struct Teacher2
{
	char a;
	int b;
	struct Teacher c;
};

void test03()
{
	struct Teacher2 t = { 'a', 10, 'b', 20 };

	int offset1 = offsetof(struct Teacher2, c);
	int offset2 = offsetof(struct Teacher, b);

	printf("c中的b数据为:%d\n", *(int*)((char*)&t + offset1 + offset2));


	printf("c中的b数据为:%d\n",   ((struct Teacher * ) ((char*)&t  +offset1))->b  );
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}