#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char name[64]; // 0 ~ 63

	int age;  // 64 ~ 67

	int id;  //68 ~ 71

	double score; // 72 ~ 79
};

//利用地址传递，可以节省资源
//缺点，如果在函数体中修改了属性，外侧的实参也被改掉
void printPerson(const struct Person *p)
{
	//p->age = 100; // 加const后防止误操作，修改属性
	printf("姓名：%s 年龄：%d 学号：%d 分数：%lf\n", p->name, p->age, p->id, p->score);
}

void test01()
{
	struct Person p1 = { "张三", 18, 1, 100 };

	printPerson(&p1);
}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}