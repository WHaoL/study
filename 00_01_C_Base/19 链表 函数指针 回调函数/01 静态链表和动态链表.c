#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//静态链表

//结点结构体设计
struct LinkNode
{
	//数据域
	int num;
	//指针域
	struct LinkNode * next;
};

void test01()
{
	//创建结点
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };

	//建立结点之间的关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//如何遍历这个链表？
	//通过一个临时的指针 从第一个结点开始访问数据，做偏移
	struct LinkNode * pCurrent = &node1;

	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);

		pCurrent = pCurrent->next;
	}
}



//动态链表
void test02()
{
	//创建结点
	struct LinkNode *  node1 = malloc(sizeof(struct LinkNode));
	node1->num = 100;
	struct LinkNode *  node2 = malloc(sizeof(struct LinkNode));
	node2->num = 200;
	struct LinkNode *  node3 = malloc(sizeof(struct LinkNode));
	node3->num = 300;
	struct LinkNode *  node4 = malloc(sizeof(struct LinkNode));
	node4->num = 400;
	struct LinkNode *  node5 = malloc(sizeof(struct LinkNode));
	node5->num = 500;

	//建立结点之间的关系
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	//遍历链表
	struct LinkNode * pCurrent = node1;
	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}

	//释放
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}