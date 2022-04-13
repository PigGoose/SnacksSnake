#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<windows.h>
#include<time.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void update()
{
	for (int i = 0; i < snake.size; i++)
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

	gotoxy(food.x, food.y);
	printf("X");

	gotoxy(tile_x, tile_y);
	printf(" ");
}

void gameOver(int mode) //1 撞自身 2 撞墙
{
	if (mode == 1)
	{
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}
	gotoxy(0, HEIGHT + 1);
	printf("Game Over！\n");
	system("pause");
	exit(1);
}

int main()
{
	srand((unsigned int)time(NULL));

	//初始化墙
	initWall();

	//初始化蛇
	initSnake();

	//初始化食物
	initFood();

	//更新显示
	update();

	char key = 'd'; //默认向右
	char preKey = 'd'; //记录上一次的方向

	while (snake.body[0].x >= 1
		&& snake.body[0].x <= WIDTH - 2
		&& snake.body[0].y >= 1
		&& snake.body[0].y <= HEIGHT - 2)
	{
		while (_kbhit())
		{
			key = _getch(); //如果没有键盘输入返回 0
		}

		if (key == 'd' && preKey == 'a' || key == 'a' && preKey == 'd'
			|| key == 'w' && preKey == 's' || key == 's' && preKey == 'w')
		{
			key = preKey;
		}
		else 
		{
			preKey = key;
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

		//检测蛇是否碰撞自身
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				gameOver(1);
			}
		}


		//判断蛇头是否碰到了食物
		if (snake.body[0].x == food.x)
		{
			snake.size++;
			initFood();
		}

		//记录当前蛇尾的位置
		tile_x = snake.body[snake.size - 1].x;
		tile_y = snake.body[snake.size - 1].y;

		for (int i = snake.size; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}

		snake.body[0].x += offset_x;
		snake.body[0].y += offset_y;

		update();
		Sleep(500);
	}

	gameOver(2);

	return EXIT_SUCCESS;
}