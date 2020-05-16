#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int id; //学号
	char * name; //姓名的 指针
	float score; //分数
};

void test01()
{
	struct student s1 = { 1, "hello world", 99 };

	printf("%c\n", s1.name[0]);

	//s1.name[0] = 'x'; //error "hello world"在常量区
}

//结构体成员 创建在堆区
void test02()
{
	struct student s1 = {1 , NULL , 100};

	//将名称设置在堆区
	s1.name =  malloc(sizeof(char)* 64);
	strcpy(s1.name, "Tom");
	strcpy(s1.name, "Jerry");
	printf("id =%d name = %s score = %f\n", s1.id, s1.name, s1.score);

	if (s1.name != NULL)
	{
		free(s1.name);
		s1.name = NULL;
	}
}

//结构体成员在堆区，结构体变量也在堆区创建
void test03()
{

   struct student * s1 = malloc(sizeof(struct student));

   s1->id = 1;
   s1->name = malloc(sizeof(char)* 64);
   strcpy(s1->name, "Bill");
   s1->score = 99.9;

   printf("id =%d name = %s score = %f\n", s1->id, s1->name, s1->score);

   //再释放的时候，要先释放成员，再释放结构体变量
   //释放的顺序 与构造的顺序是相反的
   if (s1->name != NULL)
   {
	   free(s1->name);
	   s1->name = NULL;
   }
   if (s1 != NULL)
   {
	   free(s1);
	   s1 = NULL;
   }
}


//const修饰结构体指针
void test04()
{
	struct student s1 = { 10, "Tom", 66 };
	struct student s2 = { 20, "Jerry", 77 };

	// *p 只读  p 可读可写     常量指针
	const struct student  * p = &s1;  //等价于 struct student const * p

	//(*p).id = 15;  //error 指针指向的值 不可以修改的

	p = &s2;  //指针的指向是可以修改的


	// p2 只读  *p2 可读可写    指针常量
	struct student *  const  p2 = &s1;

	(*p2).id = 100;  //指针指向的值 可以改
	//p2 = &s2; //指针的指向不可以修改


	// *p3  p3 都是只读的
	const struct student * const  p3 = &s1;
	//(*p3).id = 100; //error 指针指向的值 不可以修改
	//p3 = &s2; //error 指针的指向不可以修改
}

int main(){
	//test03();


	system("pause");
	return EXIT_SUCCESS;
}