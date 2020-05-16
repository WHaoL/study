#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int * getSpace()
{
	int * p = malloc(sizeof(int)* 5);

	if (p == NULL)
	{
		printf("分配内存失败\n");
		return NULL;
	}

	for (int i = 0; i < 5;i++)
	{
		p[i] = 100 + i;
	}

	return p;
}

void test01()
{
	int * p = getSpace();

	for (int i = 0; i < 5;i++)
	{
		printf("%d\n", p[i]);
	}
	//堆区数据手动开辟，手动释放
	//释放堆区数据
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


void allocateSpace(char * pp)
{
	char * temp = malloc(100);
	memset(temp, 0, 100);

	strcpy(temp, "hello world");

	pp = temp;

	free(temp);
}

void test02()
{
	char * p = NULL;

	allocateSpace(p);

	printf("%s\n", p);


}

//解决方式1  利用高级指针 修饰低级指针
void allocateSpace2(char ** pp)
{
	char * temp = malloc(100);
	memset(temp, 0, 100);
	strcpy(temp, "hello world");

	*pp = temp;
}

void test03()
{
	char * p = NULL;

	allocateSpace2(&p);

	printf("%s\n", p);

	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
}


//解决方式2  通过返回值
char * allocateSpace3()
{
	char *  temp = malloc(100);
	memset(temp, 0, 100);
	strcpy(temp, "hello world");
	return temp;
}

void test04()
{
	char * p = NULL;

	p =  allocateSpace3();

	printf("%s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}