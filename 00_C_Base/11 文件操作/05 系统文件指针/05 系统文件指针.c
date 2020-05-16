#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//stdin
void test01()
{
	int num = 0;
	printf("请重新给num赋值\n");

	fclose(stdin); //关闭设备文件  键盘

	scanf("%d", &num);
	printf("num = %d\n", num);
}

//stdout
void test02()
{
	printf("hello world1\n");
	printf("hello world2\n");
	printf("hello world3\n");

	//fclose(stdout); //关闭设备文件  屏幕

	

	FILE * fp = fopen("aa.txt", "r");
	if (fp == NULL)
	{
		perror("文件打开失败");
		//return;
	}


	fclose(stderr);

	perror("文件打开失败");
	
	printf("hello world4\n");
	printf("hello world5\n");
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}