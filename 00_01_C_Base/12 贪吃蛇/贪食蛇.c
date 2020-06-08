#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "wall.h"
//设置光标头文件
#include<windows.h>
#include "snake.h"
#include "food.h"
#include <time.h>

int score = 0; //分数
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
	//设置控制台光标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void update()
{
	//11蛇颜色
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

	//更新蛇尾 变为 空格
	if (tile_x != 0 && tile_y != 0)
	{
		gotoxy(tile_x, tile_y);
		printf(" ");
	}


	//判断是否循环
	if (isRool)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}

	//显示分数
	gotoxy(0, HEIGHT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("分数:%d\n", score);
}


void gameOver(int mode) //1、撞自身死亡  2、撞墙
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

	//去掉控制台光标
	CONSOLE_CURSOR_INFO  cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


	srand((unsigned int)time(NULL));

	//设置墙颜色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	//初始化墙
	initWall();

	//初始化蛇
	initSnake();

	//初始化食物
	initFood();

	//更新显示
	update();

	//方向变量
	char key = 'd'; //默认向右
	char preKey = 'd'; //记录上一次方向

	while (snake.body[0].x >= 1&& snake.body[0].x <= WIDTH - 2
		&& snake.body[0].y >= 1&&snake.body[0].y <= HEIGHT - 2)
	{

		// 如果没有键盘输入返回 0 
		if(_kbhit())
		{
			key = _getch(); //有键盘输入 更改方向key
		}

		if (key == 'd' && preKey == 'a' ||  key == 'a' && preKey == 'd' ||
			key == 'w' && preKey == 's' || key == 's' && preKey == 'w')
		{
			key = preKey; //当前方向 视为上一次方向
		}
		else
		{
			preKey = key; //更新上一次方向
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

		//检查蛇是否碰撞自身
		for (int i = 1; i < snake.size;i++)
		{
			if (snake.body[0].x == snake.body[i].x &&snake.body[0].y == snake.body[i].y)
			{
				gameOver(1);
			}
		}

		//判断蛇头是否碰到了食物
		if (snake.body[0].x == food.x  && snake.body[0].y == food.y)
		{
			snake.size++;
			score += 100; //更新得分
			sleepTime -= 10;
			initFood(); //刷新食物
		}

		////移动蛇
		//offset_x = 1;  //向右偏移1个单位
		//offset_y = 0;

		//记录当前蛇尾的位置
		tile_x = snake.body[snake.size - 1].x;
		tile_y = snake.body[snake.size - 1].y;

		//蛇身整体移动
		for (int i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}

		//新蛇头的记录
		snake.body[0].x += offset_x;
		snake.body[0].y += offset_y;


		//显示是否是循环状态
		if (snake.body[0].x == tile_x  && snake.body[0].y == tile_y)
		{
			isRool = 1;
		}
		else
		{
			isRool = 0;
		}

		//显示更新
		update();

		//睡眠
		Sleep(sleepTime);
	}

	
	gameOver(2);

	//system("pause");
	//getchar();
	return EXIT_SUCCESS;
}