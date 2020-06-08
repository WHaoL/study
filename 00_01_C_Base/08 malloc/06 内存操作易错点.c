#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、不要返回局部变量的地址

int * func()
{
	int a = 10; //分配在栈区，函数体执行结束后，局部变量被释放
	return &a;
}

void test01()
{
	int * p = func();
	printf("*p = %d\n", *p); //结果并不重要，现在在操作这个指针p，属于非法操作
	printf("*p = %d\n", *p);
}

//可以返回静态局部变量地址
int * func2()
{
	static int a = 10; 
	return &a;
}

void test02()
{
	int * p = func2();
	printf("*p = %d\n", *p); 
	printf("*p = %d\n", *p);
}


//3、不要操作已经释放的堆区空间
void test03()
{
	int * p = malloc(sizeof(int));
	printf("p = %d\n", p);
	*p = 1000;
	printf("*p =%d\n", *p);

	free(p);
	printf("p = %d\n", p);
	printf("*p =%d\n", *p); //error 非法操作内存
}

//不要重复释放堆区内存
void test04()
{
	int * p = malloc(sizeof(int));
	*p = 1000;
	//printf("p = %d\n", p);
	//free(p); 
	//free(p); //error不要重复释放堆区数据
	//printf("p = %d\n", p);

	//p = NULL; //当堆区数据释放过后，让指针置空

	//建议释放写法
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}


}



//同级指针修饰内存失败
void allocateSpace(int * p)
{
	p = malloc(4);

}

void test05()
{
	int * p = NULL;
	allocateSpace(p); //本质还是属于值传递，形参修饰不了实参

	*p = 1000;
	printf("%d\n", *p);
}


//解决方式1  通过返回值 分配内存
int * allocateSpace2()
{
	int * p=  malloc(4);
	return p;
}

void test06()
{
	int * p = NULL;
	p = allocateSpace2();
	*p = 1000;
	printf("%d\n", *p);
}

//解决方式2  通过二级指针 分配内存
void allocateSpace3(int **pp)
{
	// pp 二级指针值 （一级指针的地址）  
	// *pp （一级指针的值 具体数据的地址）  
	// **pp （具体数据的值）
	*pp = malloc(sizeof(int)); // *pp ====  p 实参p
	**pp = 10000;
}

void freeSpace(int * p)
{
	free(p); //可以释放内存 ，但是下面的置空只对形参p有效，实参无效
	p = NULL;
}

void test07()
{
	int * p = NULL;
	allocateSpace3(&p);

	printf("%d\n", *p);

	//释放内存函数
	freeSpace(p); //同级指针 是否释放堆区的内存空间？？？

	if (p==NULL)  //p的野指针状态，可以用二级指针 ，在函数体中修改为NULL
	{
		printf("p是空指针\n");
	}
	else
	{
		printf("p是野指针\n");
	}
}

int main(){
	test07();


	system("pause");
	return EXIT_SUCCESS;
}