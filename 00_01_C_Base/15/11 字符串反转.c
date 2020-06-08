#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void reverseString(char * str)
{
	int len = strlen(str);

	int start = 0; //首下标
	int end = len - 1; //尾下标

	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

void reverseString2(char * str)
{
	int len = strlen(str);

	char * start = str; //首指针 指向第一个元素
	char * end = str + len - 1; //尾指针  指向数组中最后一个元素

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}

}

void test01()
{
	char str[] = "abcdefg";

	//reverseString(str);

	reverseString2(str);

	// g f e d c b a 
	printf("str = %s\n", str);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}