#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//逆序打印
void reversePrint(char * str)
{
	//递归结束条件
	if (*str == '\0')
	{
		return;
	}

	reversePrint(str + 1);
	printf("%c", *str);
}

void test01()
{
	char * str = "abc";

	reversePrint(str);

}


//斐波那契数列  
// 1 1 2 3 5 8 13 21 34  55

int fibonacci(int pos)
{
	if (pos==1 || pos == 2)
	{
		return 1;
	}

	return fibonacci(pos - 1) + fibonacci(pos - 2);
}

void test02()
{
	int ret = fibonacci(10);

	printf("%d\n", ret);

}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}