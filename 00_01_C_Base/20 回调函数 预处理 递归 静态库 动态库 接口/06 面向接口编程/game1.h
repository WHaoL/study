#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player
{
	char name[64]; //�������
	int level;     //��ҵȼ�
	int exp;       //��Ҿ���
};

//��ʼ����Ϸ
void INIT_GAME_COMPANY1(void ** player, char * name);


//��������ս��  ս������ 1 ʤ��   0 ʧ��   ����1 ������Ӣ�� ����2  �������Ѷ�
int FIGHT_GAME_COMPANY1(void * player, int diff);

//�鿴������Ϣ
void PRINT_PLAYER_COMPANY1(void * player);

//������Ϸ
void  EXIT_GAME_COMPANY1(void * player);

//�ж��Ƿ�ʤ���ĺ��� ����1  ʤ��  ����2  �Ѷ�
int isWin(int winRate, int diff);

