#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、不允许向NULL和非法地址拷贝内存
void test01(){
	//char *p = NULL;
	////给p指向的内存区域拷贝内容
	//strcpy(p, "1111"); //err

	char *q = 0x1122;
	//给q指向的内存区域拷贝内容
	strcpy(q, "2222"); //err		
}

int * func()
{
	int a = 10;
	int * p = &a;
	return p;
}

//2、野指针出现情况
void test02()
{
	//指针变量未初始化
	//int * p;
	//printf("%d\n", *p);


	//指针释放后未置空
	//int *  p = malloc(sizeof(int));
	//*p = 1000;

	//printf("%d\n", *p);
	//free(p);
	//
	//printf("%d\n", *p); //野指针情况，已经释放了，但是没有置空
	

	//指针的操作 超越了变量的作用域
	int * pp = func();
	//printf("*pp = %d\n", *pp);
	//printf("*pp = %d\n", *pp);


	int * p2 = NULL;
	free(p2); //空指针可以释放
	//free(pp); //野指针不可以释放的
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}