#pragma  once
#include "wall.h"
#include <stdio.h>

//��ÿ�����
struct BOYD
{
	int x;//������x����
	int y;//������y����
};

struct Snake
{
	//�ߵ�һά����
	struct BOYD body[(WIDTH - 2) * (HEIGHT - 2)];
	//�߳���
	int size;
}snake;  // �ߵĽṹ�����


//��ʼ����
void initSnake();

//��ͷ��ƫ����   ����һ���ƶ���ƫ��
int offset_x; //xƫ��
int offset_y; //yƫ��

//��β�±�
int tile_x;
int tile_y;

//�Ƿ�ѭ��
int isRool;  //Ĭ��Ϊ0  ��ѭ��