#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player
{
	char name[64]; //玩家姓名
	int level;     //玩家等级
	int exp;       //玩家经验
};

//初始化游戏
void INIT_GAME_COMPANY1(void ** player, char * name);


//副本核心战斗  战斗返回 1 胜利   0 失败   参数1 代表传入英雄 参数2  代表副本难度
int FIGHT_GAME_COMPANY1(void * player, int diff);

//查看人物信息
void PRINT_PLAYER_COMPANY1(void * player);

//结束游戏
void  EXIT_GAME_COMPANY1(void * player);

//判断是否胜利的函数 参数1  胜率  参数2  难度
int isWin(int winRate, int diff);

