#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//整型数据 输入
void test01()
{
	int num = 0;
	printf("请重新给num赋值\n");

	//scanf(格式化内容，输入数据的地址)
	//scanf有阻塞行为，等待用户的输入
	scanf("%d", &num);

	printf("num = %d\n",num);
}

//字符型输入
void test02()
{
	char ch = 'a';
	printf("请重新给ch赋值\n");
	scanf("%c", &ch);
	printf("ch = %c\n", ch);
}

//浮点型输入
void test03()
{
	double d = 0;
	printf("请重新给d赋值\n");
	scanf("%lf", &d);
	printf("d = %.2lf\n", d);
}

//字符串 输入
void test04()
{
	char ch[64] = "";
	printf("请重新给ch赋值\n");

	scanf("%s", ch);
	printf("ch = %s\n", ch);
}

void test05()
{
	int num = 0;
	printf("请重新给num赋值\n");
	scanf("%d", &num); //\n
	printf("num = %d\n", num);

	char ch1;
	ch1 =getchar();//从缓冲区中获取一个字符

	char ch = 'a';
	printf("请重新给ch赋值\n");
	scanf("%c", &ch);
	printf("ch = %c\n", ch);

	putchar('a'); //向屏幕中打印1个字符
}

int main(){



	//test05();

	system("pause");
	return EXIT_SUCCESS;
}