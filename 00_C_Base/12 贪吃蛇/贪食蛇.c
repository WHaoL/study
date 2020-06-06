#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "wall.h"
//���ù��ͷ�ļ�
#include<windows.h>
#include "snake.h"
#include "food.h"
#include <time.h>

int score = 0; //����
int sleepTime = 300;


void gotoxy(int x, int y)
{
	if (x==0 && y == 0)
	{
		return;
	}
	COORD coord;
	coord.X = x;
	coord.Y = y;
	//���ÿ���̨���λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void update()
{
	//11����ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < snake.size;i++)
	{

		gotoxy(snake.body[i].x, snake.body[i].y);

		if (i == 0)
		{
			printf("@");
		}
		else
		{
			printf("#");
		}

	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(food.x, food.y);
	printf("X");

	//������β ��Ϊ �ո�
	if (tile_x != 0 && tile_y != 0)
	{
		gotoxy(tile_x, tile_y);
		printf(" ");
	}


	//�ж��Ƿ�ѭ��
	if (isRool)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}

	//��ʾ����
	gotoxy(0, HEIGHT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("����:%d\n", score);
}


void gameOver(int mode) //1��ײ��������  2��ײǽ
{

	if (mode == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(snake.body[0].x, snake.body[0].y);

		printf("@");
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, HEIGHT + 1);

	printf("GameOver!\n");
	system("pause");
	exit(1);

}

int main(){

	//ȥ������̨���
	CONSOLE_CURSOR_INFO  cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


	srand((unsigned int)time(NULL));

	//����ǽ��ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	//��ʼ��ǽ
	initWall();

	//��ʼ����
	initSnake();

	//��ʼ��ʳ��
	initFood();

	//������ʾ
	update();

	//�������
	char key = 'd'; //Ĭ������
	char preKey = 'd'; //��¼��һ�η���

	while (snake.body[0].x >= 1&& snake.body[0].x <= WIDTH - 2
		&& snake.body[0].y >= 1&&snake.body[0].y <= HEIGHT - 2)
	{

		// ���û�м������뷵�� 0 
		if(_kbhit())
		{
			key = _getch(); //�м������� ���ķ���key
		}

		if (key == 'd' && preKey == 'a' ||  key == 'a' && preKey == 'd' ||
			key == 'w' && preKey == 's' || key == 's' && preKey == 'w')
		{
			key = preKey; //��ǰ���� ��Ϊ��һ�η���
		}
		else
		{
			preKey = key; //������һ�η���
		}

		
		switch (key)
		{
		case 'a':
			offset_x = -1;  
			offset_y = 0;
			break;
		case 'd':
			offset_x = 1;
			offset_y = 0;
			break;
		case 'w':
			offset_x = 0;
			offset_y = -1;
			break;
		case 's':
			offset_x = 0;
			offset_y = 1;
			break;
		}

		//������Ƿ���ײ����
		for (int i = 1; i < snake.size;i++)
		{
			if (snake.body[0].x == snake.body[i].x &&snake.body[0].y == snake.body[i].y)
			{
				gameOver(1);
			}
		}

		//�ж���ͷ�Ƿ�������ʳ��
		if (snake.body[0].x == food.x  && snake.body[0].y == food.y)
		{
			snake.size++;
			score += 100; //���µ÷�
			sleepTime -= 10;
			initFood(); //ˢ��ʳ��
		}

		////�ƶ���
		//offset_x = 1;  //����ƫ��1����λ
		//offset_y = 0;

		//��¼��ǰ��β��λ��
		tile_x = snake.body[snake.size - 1].x;
		tile_y = snake.body[snake.size - 1].y;

		//���������ƶ�
		for (int i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}

		//����ͷ�ļ�¼
		snake.body[0].x += offset_x;
		snake.body[0].y += offset_y;


		//��ʾ�Ƿ���ѭ��״̬
		if (snake.body[0].x == tile_x  && snake.body[0].y == tile_y)
		{
			isRool = 1;
		}
		else
		{
			isRool = 0;
		}

		//��ʾ����
		update();

		//˯��
		Sleep(sleepTime);
	}

	
	gameOver(2);

	//system("pause");
	//getchar();
	return EXIT_SUCCESS;
}