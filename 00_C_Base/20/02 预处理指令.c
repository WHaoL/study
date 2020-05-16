#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、头文件 
//<> 包含系统头文件   ""包含自定义头文件

//2、宏定义
//宏常量   不重视作用域
//可以利用#undef  卸载宏
//没有数据类型区分
void test01()
{
#define MAX 1024
//#undef  MAX //卸载宏
}

//3、条件编译

//测试存在
#define  DEBUG
#ifdef  DEBUG

	#if 0  //自定义条件
	void func()
	{
		printf("DEBUG1版本\n");
	}
	#else 
	void func()
	{
		printf("DEBUG2版本\n");
	}
	#endif

#else 
void func()
{
	printf("RELEASE版本\n");
}

#endif


//特殊宏
void myFunc(char * p)
{
	if (p == NULL)
	{
		printf("文件：%s 的 %d行 出错\n", __FILE__, __LINE__);
		printf("日期：%s\n", __DATE__); // date 日期  data 数据
		printf("时间：%s\n", __TIME__); 
		return;
	}
}

void test02()
{
	char * p = NULL;
	myFunc(p);
}

int main(){

	//printf("%d\n", MAX);

	//func();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}