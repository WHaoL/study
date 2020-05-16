#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game1.h"
#include <time.h>
 

//使用typedef定义类型

//初始化游戏
typedef void(*INIT_GAME)(void ** player, char * name);

//副本核心战斗  战斗返回 1 胜利   0 失败   参数1 代表传入英雄 参数2  代表副本难度
typedef int(*FIGHT_GAME)(void * player, int diff);

//查看人物信息
typedef void(*PRINT_PLAYER)(void * player);

//结束游戏
typedef void(*EXIT_GAME)(void * player);


void playGame(INIT_GAME initGame, FIGHT_GAME fightGame, PRINT_PLAYER printPlayer , EXIT_GAME exitGame )
{
	//初始化游戏
	void * player = NULL;
	printf("请输入姓名：\n");

	char name[64] = { 0 };
	scanf("%s", name);

	initGame(&player, name);

	//战斗
	int diff = -1;

	while (1)
	{
		getchar();
		system("cls"); //清屏

		printf("请选择游戏的难度:\n");

		printf("1、简单\n");
		printf("2、中等\n");
		printf("3、困难\n");

		scanf("%d", &diff);

		getchar();

		int ret = fightGame(player, diff);

		if (ret == 0)
		{
			printf("战斗失败\n");
			break;
		}
		else
		{
			printf("战斗胜利\n");
			printPlayer(player);
		}
	}


	//离开游戏
	exitGame(player);
}


int main(){

	srand((unsigned int)time(NULL));

	playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_PLAYER_COMPANY1, EXIT_GAME_COMPANY1);

	system("pause");
	return EXIT_SUCCESS;
}