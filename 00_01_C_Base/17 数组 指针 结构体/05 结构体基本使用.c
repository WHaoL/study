#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���巽ʽ1 
typedef struct Person1
{
	char name[64];
	int age;  //����ṹ��ʱ�򣬲�Ҫ����Ա��ֵ
}myPerson;

void test01()
{
	myPerson p1;
}

//���巽ʽ2 
struct Person2
{
	char name[64];
	int age;  //����ṹ��ʱ�򣬲�Ҫ����Ա��ֵ
}myPerson2 = {"aaa" , 10};
void test02()
{
	printf("%s  %d\n", myPerson2.name, myPerson2.age);
}

//���巽ʽ3 ����
struct
{
	char name[64];
	int age;  //����ṹ��ʱ�򣬲�Ҫ����Ա��ֵ
}myPerson3 = { "bbb", 20 };


struct Person
{
	char name[64];
	int age;
};

void test03()
{
	//���ṹ�崴����ջ��
	struct Person p1 = { "aaa", 100 };

	printf("����:%s ����:%d\n", p1.name, p1.age);

	//���ṹ�崴���ڶ���
	struct Person * p2 = malloc(sizeof(struct Person));
	p2->age = 18;
	strcpy(p2->name, "bbb");
	printf("����:%s ����:%d\n", p2->name, p2->age);
	free(p2);
	p2 = NULL;
}


void printPerson(struct Person arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("����:%s ����:%d\n", arr[i].name, arr[i].age);
	}
}
void test04()
{
	//�ṹ�����������ջ��
	struct Person pArray[] = 
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(pArray) / sizeof(struct Person);
	printPerson(pArray, len);

	//�ṹ������ �����ڶ���
	struct Person * pArray2 = malloc(sizeof(struct Person) * 4);
	for (int i = 0; i < 4;i++)
	{
		pArray2[i].age = i + 10;

		sprintf(pArray2[i].name, "name_%d", i + 1);
	}
	printPerson(pArray2, 4);

	if (pArray2 != NULL)
	{
		free(pArray2);
		pArray2 = NULL;
	}
}

int main(){
	test04();


	system("pause");
	return EXIT_SUCCESS;
}