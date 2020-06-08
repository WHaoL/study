#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、void使用
void test01()
{
	//无类型是不可以创建变量的，因为不知道分配多少内存空间
	//void a = 10; //error
}

//2、限定函数的返回值 ,限定函数形参
int func(void)
{

	return 10;
}

void test02()
{
	//func();
	//printf("%d\n", func()); //error 不可以用%d打印void数据

	//func(10, 10);
}


//3、 void *
void test03()
{

	printf("sizeof void * = %d\n", sizeof(void *));

	//void * 称为万能指针

	void * p = NULL;

	int * pInt = NULL;
	char * pChar = NULL;

	pInt = (int *)pChar; //如果两个不相等的指针类型之间赋值，需要强制类型转换，不报警告提示


	pInt = p; //利用万能指针给其他指针赋值时候，不需要做强转就可以直接赋值
	pChar = p;

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}