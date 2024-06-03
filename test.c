#include "game.h"
#define _CRT_SECURE_NO_WARNINGS

void menu()
{
	printf("*********************************\n");
	printf("*******   扫雷小游戏    *********\n");
	printf("*******     1、play     *********\n");
	printf("*******     0、exit     *********\n");
	printf("*********************************\n");
}
void game()
{
	//为了方便，把两个数组定义成完全一样的
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化两个数组，传对应的参数进去
	//将雷盘先全都定义为0
	//将显示盘定义为*
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	Setmine(mine, ROW, COL);
	Findmine(mine, show, ROW, COL);

	//DisplayBoard(show, ROW, COL);
}
int main()
{
	int input;
	//先输入一个input判断要不要进入游戏，将其也设为循环的判断条件
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			//如果输入1，说明要玩游戏，封装一个game函数来包含游戏内容
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输错啦，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}