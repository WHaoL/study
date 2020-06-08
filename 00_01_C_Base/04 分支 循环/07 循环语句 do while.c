#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int num = 0;

	//while先判断循环条件，如果满足条件，再执行循环体代码
	//while (num > 10)
	//{
	//	printf("num = %d\n", num);
	//	num++;
	//}

	//do while 与while区别在于  do while会先执行一次循环体的代码，然后在判断条件
	do
	{
		printf("num = %d\n", num);
		num++;
	} while (num > 10);

}

//求1000以内水仙花数  
// 水仙花数指的是一个3位的数字，每个位的数字的 3次方之和还等于数字本身
// 153  =  1 + 125 + 27 = 153

void test02()
{
	//3位数的表示范围  100 ~ 999

	//1、打印出所有的三位数
	int num = 100;
	do 
	{
		//printf("num = %d\n", num);
		//2、再选出水仙花数

		// 1 2 3 

		int a = 0; //个位
		int b = 0; //十位
		int c = 0; //百位

		a = num % 10;
		b = num / 10 % 10; 
		c = num / 100;

		if (a * a * a + b * b * b + c * c * c == num)
		{
			//水仙花数字
			printf("num = %d\n", num);
		}

		num++;
	} while (num < 1000);

}

int main(){

	//test02();

	system("pause");
	return EXIT_SUCCESS;
}