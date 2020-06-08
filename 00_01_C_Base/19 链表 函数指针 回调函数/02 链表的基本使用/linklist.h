#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//结点
struct LinkNode
{
	int num;
	struct LinkNode * next;
};

//初始化链表  返回头结点，可以让用户使用我的链表
struct LinkNode* init_LinkList();

//遍历链表
void foreach_LinkList(struct LinkNode * pHeader);

//插入链表
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal);

//删除链表
void delete_LinkList(struct LinkNode * pHeader, int delVal);

//清空链表
void clear_LinkList(struct LinkNode * pHeader);

//销毁链表
void destroy_LinkList(struct LinkNode * pHeader);

//反转链表
void reverse_LinkList(struct LinkNode * pHeader);

//统计链表长度
int size_LinkList(struct LinkNode * pHeader);