#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{

	//for(起始表达式 ； 条件表达式； 末尾循环体) { 循环代码}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}


	//for循环中的3个内容可以省略的 ,分号不可以省略
	//int j = 0;
	//for (;;)
	//{
	//	if (j == 10)
	//	{
	//		break;
	//	}
	//	printf("%d\n", j);
	//	j++;
	//}



}

//从1 到 100 数数字，如果数字个位数字有7 ，或者 7的倍数，或者十位数字有7 ，打印敲桌子
void test02()
{

	for (int i = 1; i <= 100; i++)
	{
		//满足 7的倍数  个位为7  或者 十位为7
		if ( i % 7 == 0  || i%10 == 7 || i/ 10 ==7 )
		{
			printf("敲桌子\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}

//循环嵌套循环
void test03()
{
	//外层循环控制行 i ，内层循环控制列 j
	for (int i= 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}