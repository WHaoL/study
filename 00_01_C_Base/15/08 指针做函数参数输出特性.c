#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������ԣ��������������ڴ棬��������ʹ��

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