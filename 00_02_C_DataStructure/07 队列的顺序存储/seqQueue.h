#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

#define  MAX 1024

typedef void * seqQueue;

//��ʼ������
seqQueue init_seqQueue();

//���
void push_seqQueue(seqQueue queue, void * data);

//����
void pop_seqQueue(seqQueue queue);

//���ض�ͷ
void * front_seqQueue(seqQueue queue);

//���ض�β
void * back_seqQueue(seqQueue queue);

//���д�С
int size_seqQueue(seqQueue queue);

//�ж��Ƿ�Ϊ��
int isEmpty_seqQueue(seqQueue queue);

//���ٶ���
void destroy_seqQueue(seqQueue queue);



