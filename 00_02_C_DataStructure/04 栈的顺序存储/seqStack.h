#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define  MAX 1024

//栈的结构体
struct SStack
{
	void * data[MAX]; //栈内部真实的结构
	int m_Size; //栈的大小
};

typedef void * SeqStack;

//初始化
SeqStack init_SeqStack();

//入栈
void push_SeqStack(SeqStack stack, void * data);

//出栈
void pop_SeqStack(SeqStack stack);

//返回栈顶
void * top_SeqStack(SeqStack stack);

//返回大小
int size_SeqStack(SeqStack stack);

//判断是否为空
int isEmpty_SeqStack(SeqStack stack);

//销毁
void destroy_SeqStack(SeqStack stack);

