#pragma once
#include "wall.h"
#include <stdio.h>

struct BODY
{
	int x; //蛇身体的x坐标
	int y; //蛇身体的y坐标
};

//蛇结构体
struct Snake
{
	//蛇的一维数组
	struct BODY body[(WIDTH - 2) * (HEIGHT - 2)];
	//蛇的长度
	int size;
}snake; //蛇的结构体变量

//蛇的初始化
void initSnake();

//蛇的偏移量
int offset_x; //x偏移
int offset_y; //y便宜

//蛇尾下标
int tile_x;
int tile_y;