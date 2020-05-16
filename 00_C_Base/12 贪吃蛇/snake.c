#include "snake.h"

//初始化蛇
void initSnake()
{
	//初始化3个蛇身
	snake.size = 3;

	//蛇头
	snake.body[0].x = WIDTH / 2;
	snake.body[0].y = HEIGHT / 2;

	//蛇身
	snake.body[1].x = WIDTH / 2 - 1;
	snake.body[1].y = HEIGHT / 2;

	snake.body[2].x = WIDTH / 2 - 2;
	snake.body[2].y = HEIGHT / 2;

}