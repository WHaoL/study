#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//calloc
//calloc��malloc��ͬ�����ڶ��������ڴ�
//calloc��malloc��ͬ����calloc������ڴ棬��malloc����
void test01()
{
	//malloc��������ڴ�
	//int * p= malloc(sizeof(int)* 10);

	//calloc������ڴ�Ϊ0
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

	//���·����ڴ�  ����20��int��С,�¿ռ�����ݲ������
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