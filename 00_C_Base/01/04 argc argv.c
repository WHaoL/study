#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//命令行传入参数
//argc 命令行变量数量  
//argv 具体命令数组
int main(int argc ,char * argv[])
{
	printf("命令行变量数量 = %d\n", argc);

	//如果命令数量大于1
	//-std = c99
	if (argc > 1)
	{
		//利用循环 打印出所有命令具体是什么信息
		//int i = 0;
		for (int i = 0; i < argc;i++)
		{
			printf("%s\n", argv[i]);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}

