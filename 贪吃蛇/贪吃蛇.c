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

void gameOver(int mode) //1 ײ���� 2 ײǽ
{
	if (mode == 1)
	{
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}
	gotoxy(0, HEIGHT + 1);
	printf("Game Over��\n");
	system("pause");
	exit(1);
}

int main()
{
	srand((unsigned int)time(NULL));

	//��ʼ��ǽ
	initWall();

	//��ʼ����
	initSnake();

	//��ʼ��ʳ��
	initFood();

	//������ʾ
	update();

	char key = 'd'; //Ĭ������
	char preKey = 'd'; //��¼��һ�εķ���

	while (snake.body[0].x >= 1
		&& snake.body[0].x <= WIDTH - 2
		&& snake.body[0].y >= 1
		&& snake.body[0].y <= HEIGHT - 2)
	{
		while (_kbhit())
		{
			key = _getch(); //���û�м������뷵�� 0
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

		//������Ƿ���ײ����
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				gameOver(1);
			}
		}


		//�ж���ͷ�Ƿ�������ʳ��
		if (snake.body[0].x == food.x)
		{
			snake.size++;
			initFood();
		}

		//��¼��ǰ��β��λ��
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