#include "game1.h"

//初始化游戏
void INIT_GAME_COMPANY1(void ** player, char * name)
{
	//开辟玩家内存空间,并初始化玩家
	struct Player * p = malloc(sizeof(struct Player));

	if (p == NULL)
	{
		printf("分配内存失败\n");
		return;
	}
	
	strcpy(p->name, name);
	p->level = 0;
	p->exp = 0;

	*player = p;
}

//副本核心战斗  战斗返回 1 胜利   0 失败   参数1 代表传入英雄 参数2  代表副本难度
int FIGHT_GAME_COMPANY1(void * p, int diff)
{
	struct Player * player = p;

	int addExp  =0; //经验加成

	switch (diff)
	{
	case 1:  // 简单胜利概率为 90%
		addExp = isWin(90, 1);  // isWin来判断玩家是否胜利，如果胜利返回增加的经验，如果失败返回0
		break;
	case 2:  // 中等胜利概率为 50%
		addExp = isWin(50, 2);
		break;
	case 3:  // 困难胜利概率为 30%
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}

	//将胜利后经验 累加到玩家上
	player->exp += addExp;

	player->level = player->exp / 10;

	if (addExp == 0)  //失败
	{
		return 0;
	}
	else //胜利
	{
		return 1;
	}

}


//判断是否胜利的函数 参数1  胜率  参数2  难度
int isWin(int winRate, int diff)
{
	int random = rand() % 100 + 1;  // 1 ~ 100

	if (random <= winRate)
	{
		//胜利
		return diff * 10; //胜利增加经验   难度 * 10
	}
	else
	{
		return 0; //失败不增加经验
	}

}

//查看人物信息
void PRINT_PLAYER_COMPANY1(void * p)
{
	struct Player * player = p;
	printf("玩家<%s> ---- 当前等级<%d> ----  当前经验<%d>\n", player->name, player->level, player->exp);

}

//结束游戏
void  EXIT_GAME_COMPANY1(void * player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}