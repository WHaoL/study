#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkQueue.h"


struct Person
{
	void * node;
	char name[64];
	int age;
};
void test01()
{
	//��ʼ������
	LinkQueue queue = init_LinkQueue();

	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//���
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);

	printf("���д�СΪ:%d\n", size_LinkQueue(queue)); //5

	//������в�Ϊ�գ��鿴��ͷ���鿴��β������
	while (!isEmpty_LinkQueue(queue))
	{
		struct Person * pFront = front_LinkQueue(queue);
		printf("��ʽ�洢 --- ��ͷԪ��---������%s ���䣺%d\n", pFront->name, pFront->age);

		struct Person * pBack = back_LinkQueue(queue);
		printf("��ʽ�洢 --- ��βԪ��---������%s ���䣺%d\n", pBack->name, pBack->age);

		pop_LinkQueue(queue);
	}

	printf("���д�СΪ:%d\n", size_LinkQueue(queue)); // 0

	//���ٶ���
	destroy_LinkQueue(queue);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}