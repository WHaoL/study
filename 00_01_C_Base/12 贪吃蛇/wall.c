#include "wall.h"

//��ʼ��ǽ
void initWall()
{
	for (int i = 0; i < HEIGHT;i++)
	{
		for (int j = 0; j < WIDTH;j++)
		{
			if (i == 0  || j== 0 || i== HEIGHT -1 || j == WIDTH - 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}

		if (i == 5)
		{
			printf("\t̰ʳ��");
		}
		if (i == 6)
		{
			printf("\tcreate by zt");
		}
		if (i == 7)
		{
			printf("\t�ϣ�w");
		}
		if (i == 8)
		{
			printf("\t�£�s");
		}
		if (i == 9)
		{
			printf("\t��a");
		}
		if (i == 10)
		{
			printf("\t�ң�d");
		}

		printf("\n");
	}
}