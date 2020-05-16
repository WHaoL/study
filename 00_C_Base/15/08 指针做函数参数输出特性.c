#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//输出特性：被调函数分配内存，主调函数使用

void allocateSpace(char ** pp)
{
	char * temp =  malloc(sizeof(char)* 64);
	memset(temp, 0, 64);
	strcpy(temp, "hello world!!!");

	*pp = temp;
}

void test01()
{
	char * p = NULL;

	allocateSpace(&p);

	printf("%s\n", p);

	if (p!= NULL)
	{
		free(p);
		p = NULL;
	}
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}