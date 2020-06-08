#include "food.h"

//初始化食物
void initFood()
{
	int flag = 0; //0代表没有重叠的情况

	while (1)
	{

		food.x = rand() % (WIDTH - 2) + 1;
		food.y = rand() % (HEIGHT - 2) + 1;

		//如果随机的位置和蛇身体重叠，重新随机
		for (int i = 0; i < snake.size; i++)
		{
			//有重叠
			if (snake.body[i].x == food.x  && snake.body[i].y == food.y)
			{
				flag = 1; //有重叠
				break;
			}
		}

		if (flag == 0) //没有重叠
		{
			break;
		}
	}
}