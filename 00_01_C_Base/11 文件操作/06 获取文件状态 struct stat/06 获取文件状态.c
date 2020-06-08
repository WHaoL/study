#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <time.h> //ctime的头文件

//stat 函数
void test01()
{
	struct stat mystat;
	stat("test.txt", &mystat);

	//获取文件大小
	printf("文件的大小为：%d\n", mystat.st_size);


	//创建日期  
	char * str = ctime(&mystat.st_atime);
	char atime[1024] = { 0 };

	//方式1 
	//strcpy(atime, str);
	//atime[strlen(atime) - 1] = '\0';

	//方式2 
	strncpy(atime, str, strlen(str) - 1);


	printf("%s\n", atime);


	str = ctime(&mystat.st_mtime);
	char mtime[1024] = { 0 };
	strncpy(mtime, str, strlen(str) - 1);
	printf("%s\n", mtime);
}

//重命名文件  删除文件
void test02()
{
	//重命名
	rename("test.txt", "test2.txt");

	//删除  如果文件存在，执行删除，如果不存在，没有效果
	remove("aaa.txt");
}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}