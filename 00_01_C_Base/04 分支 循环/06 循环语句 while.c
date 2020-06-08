#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//while循环
void test01()
{
	int num = 0;

	while (num < 10)
	{
		printf("num = %d\n", num);
		//循环必须得有一个退出的条件,否则会进入死循环
		num++;
	}
}


// 猜数字游戏
// 让系统产生一个随机数 在1~100之间 , 我们进行猜测，
// 如果猜错，提示猜测过大还是过小，如果猜对，恭喜用户，结束游戏

void test02()
{
	//设置随机数种子  根据系统提供的时间会得到不同结果
	// 从1970 1 月 1日  0:00:00 开始 到目前为止的时间的秒数

	srand((unsigned int)time(NULL));//获取当前系统时间


	//int i = 0;
	//while (i<10)
	//{
	//	int num = rand() % 100 + 1; //  0 +1  ~ 99  + 1   ->  1 ~ 100
	//	printf("%d\n", num);
	//	i++;
	//}

	//1、产生随机数
	int num = rand() % 100 + 1;

	//2、玩家进行猜测

	int val = 0; //接受玩家输入猜测数字

	while (1)
	{
		//玩家输入了一个数字
		scanf("%d", &val);

		//3、判断玩家的猜测

		if (val > num) //用户输入数字大了
		{
			printf("您输入的数字过大\n");
		}
		else if (val < num)
		{
			printf("您输入的数字过小\n");
		}
		else
		{
			//猜对了
			printf("恭喜您猜对了！\n");
			//退出循环 利用break可以退出当前循环
			break;
		}
	}
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}