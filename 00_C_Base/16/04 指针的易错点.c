#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	char * p = malloc(sizeof(char)* 64);

	char *pp = p; //利用临时指针 指向p，操作临时指针，不会移动p指针

	for (int i = 0; i < 10;i++)
	{
		*pp = i + 97;
		printf("%c\n", *pp); // a ~ 97   A ~ 65   0 ~ 48
		pp++; //指针的偏移改变指针的指向，释放出错
	}

	if (p != NULL)
	{
		free(p);
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}