#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//单行 if语句
void test01()
{
	//如果输入的数据 大于600分，认为考试一本大学，进行输出
	int score = 0;

	printf("请输入一个分数：\n");

	scanf("%d", &score);

	printf("您输入的分数为：%d\n", score);

	//语法： if（满足条件）{ 满足条件成立，执行的语句 }
	if (score > 600)
	{
		printf("考上了一本大学！\n");
	}
}

//多行if语句
void test02()
{
	//如果输入的数据 大于600分，认为考试一本大学，输出，没有考上一本，也输出
	int score = 0;

	printf("请输入一个分数：\n");

	scanf("%d", &score);

	printf("您输入的分数为：%d\n", score);

	if (score > 600)
	{
		printf("考上了一本大学！\n");
	}
	else //未满足条件  进入代码体
	{
		printf("未考上一本大学\n");
	}
}

//多条件if语句
void test03()
{
	//如果输入的数据 大于600分，认为考试一本大学,大于500 ，考上二本，大于400 考上三本，小于等于400，没考上本科
	int score = 0;

	printf("请输入一个分数：\n");

	scanf("%d", &score);

	printf("您输入的分数为：%d\n", score);


	if (score > 600)
	{
		printf("考上了一本大学！\n");
	}
	else if (score > 500)
	{
		printf("考上了二本大学！\n");
	}
	else if (score > 400)
	{
		printf("考上了三本大学！\n");
	}
	else
	{
		printf("没有考上本科！\n");
	}
}

//if语句 嵌套 if语句
void test04()
{
	int score = 0;

	printf("请输入一个分数：\n");

	scanf("%d", &score);

	printf("您输入的分数为：%d\n", score);

	//考上一本了，如果是大于700分，认为考上北大，大于650，考上清华，其余，考上人大
	if (score > 600)
	{
		printf("考上了一本大学！\n");

		if (score > 700)
		{
			printf("恭喜你考入了北大！\n");
		}
		else if (score > 650)
		{
			printf("恭喜你考入了清华！\n");
		}
		else
		{
			printf("恭喜你考入了人大！\n");
		}

	}
	else if (score > 500)
	{
		printf("考上了二本大学！\n");
	}
	else if (score > 400)
	{
		printf("考上了三本大学！\n");
	}
	else
	{
		printf("没有考上本科！\n");
	}

}


//if语句的注意事项
void test05()
{
	//1、不要在if语句的后面加 分号;
	int a = 10;
	int b = 20;
	//if (a > b); //如果加入分号，后面的代码肯定会执行
	//{
	//	printf("a > b\n");
	//}

	//2、if语句实现体中如果不加{},只能识别最近的一行代码
	//if (a > b)
	//	printf("a > b\n");
	//printf("a > b\n");


	//3、做对比操作的时候，不要写成 =  ，而是用 ==
	int num = 5;
	if (num = 10) //error 不要写成 = 
	{
		printf("num == 10\n");
	}
	else
	{
		printf("num != 10\n");
	}

}

//三只小猪称体重
void test06()
{
	//1、创建三只小猪体重 变量 
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	//2、用户输入这三只猪的体重
	printf("请给小猪A体重赋值：\n");
	scanf("%d", &num1);

	printf("请给小猪B体重赋值：\n");
	scanf("%d", &num2);

	printf("请给小猪C体重赋值：\n");
	scanf("%d", &num3);

	printf("小猪A的体重为:%d\n", num1);
	printf("小猪B的体重为:%d\n", num2);
	printf("小猪C的体重为:%d\n", num3);

	//3、对比 谁最重
	if (num1 > num2) //A  比  B 重
	{
		if (num1 > num3) // A 最重
		{
			printf("小猪A最重,体重为%d斤\n", num1);
		}
		else //C最重
		{
			printf("小猪C最重,体重为%d斤\n", num3);
		}
	}
	else  //B 比 A 重
	{
		if (num2 > num3) // B最重
		{
			printf("小猪B最重,体重为%d斤\n", num2);
		}
		else //C最重
		{
			printf("小猪C最重,体重为%d斤\n", num3);
		}
	}

}

int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}