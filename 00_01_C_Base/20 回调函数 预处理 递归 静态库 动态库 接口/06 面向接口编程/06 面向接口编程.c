#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game1.h"
#include <time.h>
 

//ʹ��typedef��������

//��ʼ����Ϸ
typedef void(*INIT_GAME)(void ** player, char * name);

//��������ս��  ս������ 1 ʤ��   0 ʧ��   ����1 ������Ӣ�� ����2  �������Ѷ�
typedef int(*FIGHT_GAME)(void * player, int diff);

//�鿴������Ϣ
typedef void(*PRINT_PLAYER)(void * player);

//������Ϸ
typedef void(*EXIT_GAME)(void * player);


void playGame(INIT_GAME initGame, FIGHT_GAME fightGame, PRINT_PLAYER printPlayer , EXIT_GAME exitGame )
{
	//��ʼ����Ϸ
	void * player = NULL;
	printf("������������\n");

	char name[64] = { 0 };
	scanf("%s", name);

	initGame(&player, name);

	//ս��
	int diff = -1;

	while (1)
	{
		getchar();
		system("cls"); //����

		printf("��ѡ����Ϸ���Ѷ�:\n");

		printf("1����\n");
		printf("2���е�\n");
		printf("3������\n");

		scanf("%d", &diff);

		getchar();

		int ret = fightGame(player, diff);

		if (ret == 0)
		{
			printf("ս��ʧ��\n");
			break;
		}
		else
		{
			printf("ս��ʤ��\n");
			printPlayer(player);
		}
	}


	//�뿪��Ϸ
	exitGame(player);
}


int main(){

	srand((unsigned int)time(NULL));

	playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_PLAYER_COMPANY1, EXIT_GAME_COMPANY1);

	system("pause");
	return EXIT_SUCCESS;
}