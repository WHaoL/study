#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、sizeof的本质 
// 是不是一个函数？？？ 不是函数  
// 是一个运算符    + - * /
void test01()
{
	//如果sizeof里面是一个类型，必须加括号
	printf("sizeof int = %d\n", sizeof(int)); 


	//如果统计的是变量，可以不加括号
	int a = 10;
	printf("sizeof int = %d\n", sizeof a);

}


//2、sizeof返回值类型  unsigned int
void test02()
{
	//unsigned int a = 10;
	//if (a - 20 > 0) //当一个unsigned int和int运算时候，先都转为 unsigned int
	//{
	//	printf("大于0\n");
	//}
	//else
	//{
	//	printf("小于0\n");
	//}

	if ( sizeof(int) - 5 > 0)
	{
		printf("大于0\n");
		printf("%u\n", sizeof(int)-5);
	}
	else
	{
		printf("小于0\n");
	}

}

//3、统计数组长度
//当传入到函数中，数组名被退化为一个指针，指向数组中第一个元素的地址
void calculateArray(int * arr)
{
	printf("calculateArray: %d\n", sizeof(arr));

}

void test03()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	printf("test03: %d\n", sizeof(arr));

	calculateArray(arr);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}