#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//文件中每一行的内容是一个四则运算的表达式
//类似于   1 + 1 = 
//需求1 ： 写一个函数，自动出50个题目，操作数是 1 ~ 100之间，运算符为  + - * / 随机  15 ~ 20 min实现

//需求2 ： 在写一个函数，将所有的题目解析，完成50题的答案， 类似于  1 + 1 = 2

//出题函数
void setQuestion()
{
	//1、准备变量  存放 操作数 
	int num1 = 0;
	int num2 = 0;
	char ch = 0;

	char oper[] = { '+', '-', '*', '/' };

	//2、打开文件  写的方式打开
	FILE * fp = fopen("test.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//3、准备写入的字符串  
	// 3.1 随机数  1 ~ 100 
	// 3.2 字符  随机+ - * /
	// 3.3 将准备的字符串 拼接到一起    1 + 1 =

	for (int i = 0; i < 50;i++)
	{
		num1 = rand() % 100 + 1;  // 1 ~ 100
		num2 = rand() % 100 + 1;  // 1 ~ 100
		ch = oper[rand() % 4];    // 0 ~ 3

		char buf[128] = { 0 };

		sprintf(buf, "%d %c %d =\n",num1,ch,num2);

		//printf("%s\n", buf);
		//4、 fputs 写入到文件中
		fputs(buf, fp);

	}

	//5、关闭文件 
	fclose(fp);

	printf("50道题目出题完毕\n");
}

//解析函数
void answerQuestion()
{
	FILE * fp1 = fopen("test.txt", "r");
	FILE * fp2 = fopen("test2.txt", "w");

	if ( fp1 == NULL || fp2 == NULL )
	{
		printf("文件打开失败\n");
		return;
	}

	char buf[1024] = { 0 };

	while (fgets(buf, sizeof(buf), fp1))
	{
		int num1 = 0;
		int num2 = 0;
		char ch = 0;
		//printf("%s", buf);  // 50 + 7 = 

		//数据拆分
		sscanf(buf, "%d %c %d =", &num1, &ch, &num2);
		//printf("num1 = %d\n", num1);
		//printf("num2 = %d\n", num2);
		//printf("ch = %c\n", ch);
		int ret = 0;

		switch (ch)
		{
		case '+':
			ret = num1 + num2;
			break;
		case '-':
			ret = num1 - num2;
			break;
		case '*':
			ret = num1 * num2;
			break;
		case '/':
			ret = num1 / num2;
			break;
		default:
			break;
		}

		//将结果组装成一个字符串 ，写入到文件中
		char str[128] = { 0 };
		sprintf(str, "%d %c %d = %d\n", num1, ch, num2, ret);

		fputs(str, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	printf("50道题目解答完毕\n");

}


int main(){
	//随机数种子
	srand((unsigned int)time(NULL));

	//setQuestion();

	answerQuestion();

	system("pause");
	return EXIT_SUCCESS;
}