#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>

struct Teacher
{
	char a; //0~3
	int b;  //4~7 
};

void test01()
{
	struct Teacher t1;
	struct Teacher *p = &t1;

	printf("b��ƫ��Ϊ��%d\n", (int)&(p->b) - (int)p);

	printf("b��ƫ��Ϊ��%d\n",offsetof(struct Teacher,b) );
}

//ͨ��ƫ������ȡ����
void test02()
{
	struct Teacher t1 = {'a' , 10};

	printf("b��ֵΪ��%d\n", *(int*)((char *)&t1 + offsetof(struct Teacher, b)));
	printf("b��ֵΪ��%d\n", *(int*)((int *)&t1 + 1 ));
}

//�ṹ��Ƕ�׽ṹ��
struct Teacher2
{
	char a;
	int b;
	struct Teacher c;
};

void test03()
{
	struct Teacher2 t = { 'a', 10, 'b', 20 };

	int offset1 = offsetof(struct Teacher2, c);
	int offset2 = offsetof(struct Teacher, b);

	printf("c�е�b����Ϊ:%d\n", *(int*)((char*)&t + offset1 + offset2));


	printf("c�е�b����Ϊ:%d\n",   ((struct Teacher * ) ((char*)&t  +offset1))->b  );
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}