#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��װһ�����������Դ�ӡ�����������͵�����
void printAllType(void * data , void(*myPrint)(void *))
{
	//printf("%lf\n", *(int *)data);

	//��ӡ��Ҫ�������û�ȥ����
	myPrint(data);
}

//�ص���������ʼ�ǲ����õģ������ض�������ȥ����
void printInt(void * data)
{
	int * num = data;
	printf("%d\n", *num);
}

void test01()
{
	int a = 10;

	printAllType(&a, printInt);

	//double b = 3.14;

	//printAllType(&b);
}

struct Person
{
	char name[64];
	int age;
};
//�û��ṩһ���ص�����
void printPerson(void *data)
{
	struct Person * p = data;
	printf("����:%s  ����:%d\n", p->name, p->age);
}
void test02()
{
	struct Person p1 = { "aaa", 10 };

	printAllType(&p1, printPerson);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}