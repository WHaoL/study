#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


////结点结构体
//struct LinkNode
//{
//	//只维护指针域
//	struct LinkNode * next;
//};
//
////链表结构体
//struct LList
//{
//	//链表头结点
//	struct LinkNode pHeader;
//	//链表长度
//	int m_Size;
//};

typedef void * LinkList;


//初始化链表
LinkList init_LinkList();


//插入链表
void insert_LinkList(LinkList list, int pos, void * data);

//遍历链表
void foreach_LinkList(LinkList list, void(*myPrint)(void *));

//删除链表
void removeByPos_LinkList(LinkList list, int pos);

//销毁链表
void destroy_LinkList(LinkList list);


