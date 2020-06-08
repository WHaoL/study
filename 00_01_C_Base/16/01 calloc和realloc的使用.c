#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//calloc
//calloc和malloc相同点是在堆区分配内存
//calloc和malloc不同点是calloc会清空内存，而malloc不会
void test01()
{
	//malloc不会清空内存
	//int * p= malloc(sizeof(int)* 10);

	//calloc会清空内存为0
	int * p = calloc(10, sizeof(int));

	for (int i = 0; i < 10;i++)
	{
		printf("%d\n", p[i]);
	}

	if (p!= NULL)
	{
		free(p);
		p = NULL;
	}

}


//realloc
void test02()
{
	int * p = malloc(sizeof(int)* 10);

	for (int i = 0; i < 10;i++)
	{
		p[i] = 100 + i;
	}

	for (int i = 0; i < 10;i++)
	{
		printf("%d\n", p[i]);
	}

	printf("%d\n", p);

	//重新分配内存  分配20个int大小,新空间的数据不会清空
	p = realloc(p, sizeof(int)* 20);

	printf("%d\n", p);

	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", p[i]);
	}

	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}