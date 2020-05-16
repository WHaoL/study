#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//void //无类型
	//int a = 10;
	//void b = 20;  不可以通过无类型创建变量
}
void test02()
{
	void * p = NULL; //4个字节
	printf("sizeof p = %d\n", sizeof(void *));

	int a = 10;
	p = &a;

	//void * 不可以解引用
	printf("a = %d\n", *(int*)p);

	//void * 通常用来保存任意数据类型的地址，因此我们也称为他是万能指针
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}