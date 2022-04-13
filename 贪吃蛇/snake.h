#pragma once
#include "wall.h"
#include <stdio.h>

struct BODY
{
	int x; //�������x����
	int y; //�������y����
};

//�߽ṹ��
struct Snake
{
	//�ߵ�һά����
	struct BODY body[(WIDTH - 2) * (HEIGHT - 2)];
	//�ߵĳ���
	int size;
}snake; //�ߵĽṹ�����

//�ߵĳ�ʼ��
void initSnake();

//�ߵ�ƫ����
int offset_x; //xƫ��
int offset_y; //y����

//��β�±�
int tile_x;
int tile_y;