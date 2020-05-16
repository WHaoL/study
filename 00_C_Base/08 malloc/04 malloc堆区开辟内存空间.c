#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//malloc头文件   stdlib.h
//malloc申请的内存不会清空，这块内存的生命周期在整个程序结束后，才释放，也可以通过free的函数释放空间
//通常由程序员手动开辟，手动释放
//malloc返回的是申请内存空间的首地址，如果申请失败，返回NULL

void test01()
{
	int * p = malloc(sizeof(int));

	if (p == NULL)
	{
		printf("申请堆区内存失败\n");
		return;
	}

	//申请成功，操作内存
	memset(p, 0, sizeof(int));

	//操作赋值
	*p = 1000;
	printf("*p = %d\n", *p);

	//释放内存
	free(p);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}