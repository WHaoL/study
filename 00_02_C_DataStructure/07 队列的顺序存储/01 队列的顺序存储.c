#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "seqQueue.h"

struct Person
{
	char name[64];
	int age;
};
void test01()
{
	//初始化队列
	seqQueue  queue = init_seqQueue();

	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };

	//入队
	push_seqQueue(queue, &p1);
	push_seqQueue(queue, &p2);
	push_seqQueue(queue, &p3);
	push_seqQueue(queue, &p4);
	push_seqQueue(queue, &p5);

	printf("队列大小为:%d\n", size_seqQueue(queue)); //5

	//如果队列不为空，查看队头，查看队尾，出队
	while (!isEmpty_seqQueue(queue))
	{
		struct Person * pFront =  front_seqQueue(queue);
		printf("队头元素---姓名：%s 年龄：%d\n", pFront->name, pFront->age);

		struct Person * pBack = back_seqQueue(queue);
		printf("队尾元素---姓名：%s 年龄：%d\n", pBack->name, pBack->age);

		pop_seqQueue(queue);
	}

	printf("队列大小为:%d\n", size_seqQueue(queue)); // 0

	//销毁队列
	destroy_seqQueue(queue);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}