#include "game1.h"

//��ʼ����Ϸ
void INIT_GAME_COMPANY1(void ** player, char * name)
{
	//��������ڴ�ռ�,����ʼ�����
	struct Player * p = malloc(sizeof(struct Player));

	if (p == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return;
	}
	
	strcpy(p->name, name);
	p->level = 0;
	p->exp = 0;

	*player = p;
}

//��������ս��  ս������ 1 ʤ��   0 ʧ��   ����1 ������Ӣ�� ����2  �������Ѷ�
int FIGHT_GAME_COMPANY1(void * p, int diff)
{
	struct Player * player = p;

	int addExp  =0; //����ӳ�

	switch (diff)
	{
	case 1:  // ��ʤ������Ϊ 90%
		addExp = isWin(90, 1);  // isWin���ж�����Ƿ�ʤ�������ʤ���������ӵľ��飬���ʧ�ܷ���0
		break;
	case 2:  // �е�ʤ������Ϊ 50%
		addExp = isWin(50, 2);
		break;
	case 3:  // ����ʤ������Ϊ 30%
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}

	//��ʤ������ �ۼӵ������
	player->exp += addExp;

	player->level = player->exp / 10;

	if (addExp == 0)  //ʧ��
	{
		return 0;
	}
	else //ʤ��
	{
		return 1;
	}

}


//�ж��Ƿ�ʤ���ĺ��� ����1  ʤ��  ����2  �Ѷ�
int isWin(int winRate, int diff)
{
	int random = rand() % 100 + 1;  // 1 ~ 100

	if (random <= winRate)
	{
		//ʤ��
		return diff * 10; //ʤ�����Ӿ���   �Ѷ� * 10
	}
	else
	{
		return 0; //ʧ�ܲ����Ӿ���
	}

}

//�鿴������Ϣ
void PRINT_PLAYER_COMPANY1(void * p)
{
	struct Player * player = p;
	printf("���<%s> ---- ��ǰ�ȼ�<%d> ----  ��ǰ����<%d>\n", player->name, player->level, player->exp);

}

//������Ϸ
void  EXIT_GAME_COMPANY1(void * player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}