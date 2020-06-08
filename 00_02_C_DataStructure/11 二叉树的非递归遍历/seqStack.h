#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define  MAX 1024

//ջ�Ľṹ��
struct SStack
{
	void * data[MAX]; //ջ�ڲ���ʵ�Ľṹ
	int m_Size; //ջ�Ĵ�С
};

typedef void * SeqStack;

//��ʼ��
SeqStack init_SeqStack();

//��ջ
void push_SeqStack(SeqStack stack, void * data);

//��ջ
void pop_SeqStack(SeqStack stack);

//����ջ��
void * top_SeqStack(SeqStack stack);

//���ش�С
int size_SeqStack(SeqStack stack);

//�ж��Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack stack);

//����
void destroy_SeqStack(SeqStack stack);

