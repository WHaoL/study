#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//按字符方式读 test.txt
void test01()
{
	FILE * fp= fopen("test.txt", "r");

	if (fp == NULL)
	{
		return;
	}

	char ch;

	while (!feof(fp))
	{
		//feof读有滞后性
		ch = fgetc(fp);

		if (feof(fp))
		{
			break;
		}

		printf("%c", ch);
	}

	//while (  (ch = fgetc(fp))  != EOF )
	//{
	//	printf("%c",ch);
	//}


	fclose(fp);
}


//注意事项2 
struct Person
{
	char * name; //如果有属性指向堆区，那么些文件时候，要将指针指向的数据写入，而不是指针
	int age;
};

int main(){

	test01();

	//printf(" aaaa\n");
	//printf("%caaaa\n",EOF);

	system("pause");
	return EXIT_SUCCESS;
}