#pragma  once
#include "wall.h"
#include <stdio.h>

//蛇每个身段
struct BOYD
{
	int x;//蛇身体x坐标
	int y;//蛇身体y坐标
};

struct Snake
{
	//蛇的一维数组
	struct BOYD body[(WIDTH - 2) * (HEIGHT - 2)];
	//蛇长度
	int size;
}snake;  // 蛇的结构体变量


//初始化蛇
void initSnake();

//蛇头的偏移量   蛇下一步移动的偏移
int offset_x; //x偏移
int offset_y; //y偏移

//蛇尾下标
int tile_x;
int tile_y;

//是否循环
int isRool;  //默认为0  不循环