#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

#define  MAX 1024

typedef void * seqQueue;

//初始化队列
seqQueue init_seqQueue();

//入队
void push_seqQueue(seqQueue queue, void * data);

//出队
void pop_seqQueue(seqQueue queue);

//返回队头
void * front_seqQueue(seqQueue queue);

//返回队尾
void * back_seqQueue(seqQueue queue);

//队列大小
int size_seqQueue(seqQueue queue);

//判断是否为空
int isEmpty_seqQueue(seqQueue queue);

//销毁队列
void destroy_seqQueue(seqQueue queue);



