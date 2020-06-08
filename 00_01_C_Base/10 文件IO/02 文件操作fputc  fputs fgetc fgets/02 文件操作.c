#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//fopen
void test01()
{
	//利用只读的方式 打开 test.txt文件
	FILE * fp = fopen("test.txt", "r");

	if (fp == NULL)
	{
		printf("文件读取失败\n");
		return;
	}

	printf("文件打开成功\n");

	//文件关闭
	fclose(fp);
}

//2、按字符从方式 对文件读写
//fputc 按字符方式写
void test02()
{
	//1、打开文件
	FILE * fp = fopen("test2.txt", "w"); //w只写   13
	if (fp == NULL)
	{
		printf("文件打开失败\n"); 
		return;
	}

	//2、写文件
	char buf[] = "hello world\n";

	int  i = 0;
	while (buf[i]!= '\0')
	{
		//按字符写
		fputc(buf[i], fp);
		i++;
	}

	//3、关闭文件
	fclose(fp);
}


void test03()
{
	//1、打开文件
	FILE * fp = fopen("test3.txt", "wb"); //wb只写  二进制写    12
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//2、写文件
	char buf[] = "hello world\n";

	int  i = 0;
	while (buf[i] != '\0')
	{
		//按字符写
		fputc(buf[i], fp);
		i++;
	}

	//3、关闭文件
	fclose(fp);
}

//读文件  fgetc 按字符的方式读文件
void test04()
{
	//1、打开文件
	FILE * fp = fopen("test2.txt", "r");

	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//2、读文件
	char ch;

	//ch = fgetc(fp);
	//printf("%c\n", ch);  //读取一个字符

	while (  (ch= fgetc(fp) ) != EOF  )   // EOF 标志  文件结束标志   end of file
	{
		printf("%c", ch);
	}

	//3、关闭文件
	fclose(fp);

}

//从键盘获取用户输入内容，并且保存到文件中
//当用户输入 :quit 代表输入结束
void test05()
{
	FILE * fp = fopen("test5.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	while (1)
	{
		char buf[1024] = { 0 };
		fgets(buf, sizeof(buf), stdin);

		//检查用户输入的内容是不是 :quit
		if (strncmp(buf,":quit",5) == 0)
		{
			break;
		}

		//将用户输入的数据，写入到文件中
		int  i = 0; 
		while (buf[i] != '\0')
		{
			fputc(buf[i++], fp);
		}
	}

	fclose(fp);
}


int main(){
	test05();


	system("pause");
	return EXIT_SUCCESS;
}