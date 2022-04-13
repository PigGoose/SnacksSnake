#include"food.h"

//初始化食物
void initFood()
{
	int flag = 0;

	while (1)
	{
		food.x = rand() % (WIDTH - 2) + 1;
		food.y = rand() % (HEIGHT - 2) + 1;

		for (int i = 0; i < snake.size; i++)
		{
			if (snake.body[i].x == food.x && snake.body[i].y == food.y)
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