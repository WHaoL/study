#pragma  once
#include <stdio.h>
#include "wall.h"
#include "snake.h"

//食物结构体
struct Food
{
	int x;
	int y;
}food;

//初始化食物
void initFood();