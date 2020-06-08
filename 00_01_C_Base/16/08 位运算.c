#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、按位取反
void test01()
{
	int num = 2;
	printf("~num = %d\n", ~num);   //-3 

	// 0000 0000 0000 0000 0000 0000 0000 0010

	// 1111 1111 1111 1111 1111 1111 1111 1101   取反后

	// 1000 0000 0000 0000 0000 0000 0000 0011    - 3 
}

//2、按位与 &
void test02()
{
	int num = 332;

	if ( (num & 1) ==0)
	{
		printf("偶数\n");
	}
	else
	{
		printf("奇数\n");
	}
}

//3、按位或  |
void test03()
{
	int num1 = 5;
	int num2 = 3;

	printf("num1 | num2 = %d\n", num1 | num2); //7

}

//4、按位异或
void test04()
{
	//可以实现交换两个数字
	int num1 = 5;
	int num2 = 10;

	//方式一
	//int temp = num1;
	//num1 = num2;
	//num2 = temp;

	//方式二
	//num1 = num1 ^ num2; 
	//num2 = num1 ^ num2;
	//num1 = num1 ^ num2;

	//方式三
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;


	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
}


//左移  << 
void test05()
{
	int num = 10;
	printf("num <<= 3 = %d\n", num <<= 3);  //左移n位代表乘以2 ^n
}

//右移  >> 
void test06()
{
	int num = 80;
	printf("num = %d\n", num >>= 2);  //右移n位代表除以2 ^n
}



int main(){

	test06();

	system("pause");
	return EXIT_SUCCESS;
}