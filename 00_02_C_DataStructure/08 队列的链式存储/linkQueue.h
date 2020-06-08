#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//结点结构体
struct LinkNode
{
	struct LinkNode * next;
};

//队列的结构体
struct LQueue
{
	struct LinkNode pHeader; //头结点
	int m_Size;  //队列大小
	struct LinkNode * pTail; //尾结点指针
};

typedef void * LinkQueue;


//初始化队列
LinkQueue init_LinkQueue();

//入队
void push_LinkQueue(LinkQueue queue , void * data);

//出队
void pop_LinkQueue(LinkQueue queue);

//返回队头
void * front_LinkQueue(LinkQueue queue);

//返回队尾
void * back_LinkQueue(LinkQueue queue);

//返回队列大小
int size_LinkQueue(LinkQueue queue);

//判断是否为空
int isEmpty_LinkQueue(LinkQueue queue);

//销毁队列
void destroy_LinkQueue(LinkQueue queue);