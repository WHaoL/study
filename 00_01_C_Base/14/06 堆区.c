#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int * getSpace()
{
	int * p = malloc(sizeof(int)* 5);

	if (p == NULL)
	{
		printf("�����ڴ�ʧ��\n");
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
	//���������ֶ����٣��ֶ��ͷ�
	//�ͷŶ�������
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

//�����ʽ1  ���ø߼�ָ�� ���εͼ�ָ��
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


//�����ʽ2  ͨ������ֵ
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