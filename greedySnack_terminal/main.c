#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define WIDE  90
#define HIGH  40

//隐藏控制台光标
void hide_cur()
{
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

typedef struct Body
{
	int x;
	int y;
}Body;

typedef struct snack
{
	int size;
	Body body[WIDE * HIGH];
	Body food;
	Body tail;
	int offset_X;
	int offset_Y;
	COORD coord;
}Snack;

void init_snack(Snack* snack)
{
	snack->size = 2;
	snack->offset_X = 1;
	snack->offset_Y = 0;

	snack->body[0].x = WIDE / 2;
	snack->body[0].y = HIGH / 2;
	snack->body[1].x = WIDE / 2 - 1;
	snack->body[1].y = HIGH / 2;
}

void init_ui()
{
	for(int i = 0; i <= HIGH; i++)
	{
		for(int j = 0; j <= WIDE; j++)
		{
			if(i == HIGH  || j == WIDE)
			{
				printf("+");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void show_snack(Snack* snack)
{
	for(int i = 0; i < snack->size; i++)
	{
		snack->coord.X = snack->body[i].x;
		snack->coord.Y = snack->body[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snack->coord);
		if(i == 0)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}

	snack->coord.X = snack->tail.x;
	snack->coord.Y = snack->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snack->coord);
	printf(" ");

	snack->coord.X = snack->food.x;
	snack->coord.Y = snack->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snack->coord);
	printf("#");
}

void move_snack(Snack* snack)
{
	snack->tail = snack->body[snack->size - 1];
	for(int i = snack->size - 1; i > 0; i--)
	{
		snack->body[i] = snack->body[i-1];
	}
	snack->body[0].x += snack->offset_X;
	snack->body[0].y += snack->offset_Y;
}

void init_food(Snack* snack)
{
	while(1)
	{
		snack->food.x = rand() % WIDE - 1;
		snack->food.y = rand() % HIGH - 1;
		for(int i = 0; i < snack->size; i++)
		{
			if(snack->body[i].x == snack->food.x && snack->body[i].y == snack->food.y)
			{
				continue;
			}
		}
		break;
	}
	
}

void snack_eat(Snack* snack)
{
	if(snack->food.x == snack->body[0].x && snack->food.y == snack->body[0].y)
	{
		init_food(snack);
		snack->size++;
	}
}

void control_snake(Snack* snack)
{
	char ch = 0;
	while(_kbhit())
	{
		ch = getch();
	}

	switch (ch)
	{
	case 'a':
		snack->offset_X = -1;
		snack->offset_Y = 0;
		break;
	case 'w':
		snack->offset_X = 0;
		snack->offset_Y = -1;
		break;
	case 's':
		snack->offset_X = 0;
		snack->offset_Y = 1;
		break;
	case 'd':
		snack->offset_X = 1;
		snack->offset_Y = 0;
		break;
	default:
		break;
	}
}

int game_end(Snack* snack)
{
	for(int i = 1; i < snack->size; i++)
	{
		if(snack->body[i].x == snack->body[0].x && snack->body[i].y == snack->body[0].y)
		{
			return 1;
		}
	}
	return 0;
}

void game_start(Snack* snack)
{
	while(snack->body[0].x >= 0 && snack->body[0].y >= 0 && snack->body[0].x < WIDE && snack->body[0].y < HIGH)
	{
		show_snack(snack);
		control_snake(snack);
		move_snack(snack);
		snack_eat(snack);
		if(game_end(snack))
		{
			break;
		}
		Sleep(10);
	}
}

int game_ui()
{
	COORD coord;
	coord.X = 0;
	coord.Y = HIGH + 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("Do you want to play again?(1.yes  0.no):");
	char ch = getch();
	return !(ch - '0');
}


int main()
{
	while(1)
	{
		system("cls");
		srand((unsigned)time(NULL));
		Snack snack;
		hide_cur();
		init_snack(&snack);
		init_ui();
		init_food(&snack);

		game_start(&snack);

		int ret = game_ui();
		if(ret == 1)
		{
			exit(0);
		}
	}


	return 0;
}