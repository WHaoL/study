#include "food.h"

//��ʼ��ʳ��
void initFood()
{
	int flag = 0; //0����û���ص������

	while (1)
	{

		food.x = rand() % (WIDTH - 2) + 1;
		food.y = rand() % (HEIGHT - 2) + 1;

		//��������λ�ú��������ص����������
		for (int i = 0; i < snake.size; i++)
		{
			//���ص�
			if (snake.body[i].x == food.x  && snake.body[i].y == food.y)
			{
				flag = 1; //���ص�
				break;
			}
		}

		if (flag == 0) //û���ص�
		{
			break;
		}
	}
}