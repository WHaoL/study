#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//	1、无参无返
void func1()
{
	printf("this is func1\n");
}

//	2、有参无返
void func2(int a)
{
	printf("this is func2 a = %d\n",a);
	return; //可选添加
}

//	3、无参有返
int func3()
{
	printf("this is func3\n");
	return 1000;
}

//	4、有参有返  形参中的变量名 C语言下 必须写
int func4(int a)
{
	printf("this is func4 a = %d\n",a);
	return a;
}

void test01()
{
	//1、无参无返
	func1();
	//2、 有参无返
	func2(10);
	//3、无参有返  返回值 可以在调用时候接受或者不接受
    int num = func3();
	printf("num = %d\n", num);
	//4、有参有返
	int num2 = func4(10000);
	printf("num2 = %d\n", num2);

}


//定义函数，获取 1 ~  10之间随机数
int getRandom(int min,int max)
{

	int random = rand() % max + min;     // 1 ~ 100  max=100 min=1

	return random;
}

void test02()
{
	//设置随机数种子
	srand((size_t)time(NULL)); //size_t 等价于 unsigned int

	//printf("%d\n", time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int random = getRandom(1, 100); // 1 ~ 100
		printf("random = %d\n", random);
	}

	
}



int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}