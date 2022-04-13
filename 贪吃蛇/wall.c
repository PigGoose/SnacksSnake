#include"wall.h"

//≥ı ºªØ«Ω
void initWall()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
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
			printf("\tÃ∞≥‘…ﬂ");
		}
		if (i == 6)
		{
			printf("\t…œ:w");
		}
		if (i == 7)
		{
			printf("\tœ¬:s");
		}
		if (i == 8)
		{
			printf("\t◊Û:a");
		}
		if (i == 9)
		{
			printf("\t”“:d");
		}
		printf("\n");
	}
}