#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//typedef��ʹ��

//1��typedef�ؼ���   ԭ��   ������
typedef int MYINT;

void test01()
{
	int a = 10;
	MYINT b = 20;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}


//2�����Ը��ṹ�������
typedef struct itcastStudentInfo
{
	char name[64];
	int age;
}student;

void test02()
{
	struct itcastStudentInfo s1 = { "Tom", 19 };

	student s2 = { "Jerry", 20 };
}


//3���ṹ��ָ������
typedef struct itcastStudentInfo2
{
	char name[64];
	int age;
}stu,*pStu;  // stu  -> struct itcastStudentInfo2   pStu -> struct itcastStudentInfo2 *  ====  stu *

void test03()
{
	stu s = { "aaa", 10 };

	pStu p = &s;

	printf("����:%s  ����:%d\n", p->name, p->age);

}

int main(){

	//test01();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}