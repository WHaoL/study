#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//break  ： 
// 1  switch 中跳出分支， 
// 2  循环中退出当层循环， 
// 3  嵌套循环中退出 内层循环
void test01()
{
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			printf("* ");
		}
		printf("\n");
	}
}


//continue
void test02()
{
	//跳过本次剩余的代码，执行下一次的循环

	for (int i = 0; i < 100;i++)
	{
		if (i % 2 == 0)
		{	
			continue; //不会退出循环，而break 会退出循环
		}
		printf("i = %d\n", i);
	}
}

//goto  无条件跳转语句
//由于容易让程序混乱，不建议用
void test03()
{
	printf("1\n");
	printf("2\n");

	goto FALG;

	printf("3\n");
	printf("4\n");

FALG:
	printf("5\n");
	printf("6\n");
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}