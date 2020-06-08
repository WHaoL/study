#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1����Ҫ���ؾֲ������ĵ�ַ

int * func()
{
	int a = 10; //������ջ����������ִ�н����󣬾ֲ��������ͷ�
	return &a;
}

void test01()
{
	int * p = func();
	printf("*p = %d\n", *p); //���������Ҫ�������ڲ������ָ��p�����ڷǷ�����
	printf("*p = %d\n", *p);
}

//���Է��ؾ�̬�ֲ�������ַ
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


//3����Ҫ�����Ѿ��ͷŵĶ����ռ�
void test03()
{
	int * p = malloc(sizeof(int));
	printf("p = %d\n", p);
	*p = 1000;
	printf("*p =%d\n", *p);

	free(p);
	printf("p = %d\n", p);
	printf("*p =%d\n", *p); //error �Ƿ������ڴ�
}

//��Ҫ�ظ��ͷŶ����ڴ�
void test04()
{
	int * p = malloc(sizeof(int));
	*p = 1000;
	//printf("p = %d\n", p);
	//free(p); 
	//free(p); //error��Ҫ�ظ��ͷŶ�������
	//printf("p = %d\n", p);

	//p = NULL; //�����������ͷŹ�����ָ���ÿ�

	//�����ͷ�д��
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



//ͬ��ָ�������ڴ�ʧ��
void allocateSpace(int * p)
{
	p = malloc(4);

}

void test05()
{
	int * p = NULL;
	allocateSpace(p); //���ʻ�������ֵ���ݣ��β����β���ʵ��

	*p = 1000;
	printf("%d\n", *p);
}


//�����ʽ1  ͨ������ֵ �����ڴ�
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

//�����ʽ2  ͨ������ָ�� �����ڴ�
void allocateSpace3(int **pp)
{
	// pp ����ָ��ֵ ��һ��ָ��ĵ�ַ��  
	// *pp ��һ��ָ���ֵ �������ݵĵ�ַ��  
	// **pp ���������ݵ�ֵ��
	*pp = malloc(sizeof(int)); // *pp ====  p ʵ��p
	**pp = 10000;
}

void freeSpace(int * p)
{
	free(p); //�����ͷ��ڴ� ������������ÿ�ֻ���β�p��Ч��ʵ����Ч
	p = NULL;
}

void test07()
{
	int * p = NULL;
	allocateSpace3(&p);

	printf("%d\n", *p);

	//�ͷ��ڴ溯��
	freeSpace(p); //ͬ��ָ�� �Ƿ��ͷŶ������ڴ�ռ䣿����

	if (p==NULL)  //p��Ұָ��״̬�������ö���ָ�� ���ں��������޸�ΪNULL
	{
		printf("p�ǿ�ָ��\n");
	}
	else
	{
		printf("p��Ұָ��\n");
	}
}

int main(){
	test07();


	system("pause");
	return EXIT_SUCCESS;
}