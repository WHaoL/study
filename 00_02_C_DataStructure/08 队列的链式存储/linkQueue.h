#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���ṹ��
struct LinkNode
{
	struct LinkNode * next;
};

//���еĽṹ��
struct LQueue
{
	struct LinkNode pHeader; //ͷ���
	int m_Size;  //���д�С
	struct LinkNode * pTail; //β���ָ��
};

typedef void * LinkQueue;


//��ʼ������
LinkQueue init_LinkQueue();

//���
void push_LinkQueue(LinkQueue queue , void * data);

//����
void pop_LinkQueue(LinkQueue queue);

//���ض�ͷ
void * front_LinkQueue(LinkQueue queue);

//���ض�β
void * back_LinkQueue(LinkQueue queue);

//���ض��д�С
int size_LinkQueue(LinkQueue queue);

//�ж��Ƿ�Ϊ��
int isEmpty_LinkQueue(LinkQueue queue);

//���ٶ���
void destroy_LinkQueue(LinkQueue queue);