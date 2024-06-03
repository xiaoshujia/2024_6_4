#include "game.h"
#define _CRT_SECURE_NO_WARNINGS
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < cols; y++)
		{
			board[x][y] = ret;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("--------扫雷---------\n");
	for (x = 0; x <= row; x++)
	{
		printf("%d ", x);
	}
	printf("\n");
	for (x = 1; x <= row; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= col; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}
//布置雷
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = COUNT_EASY;  //雷的数量
	while (count)//当没布置完雷之前都继续循环
	{
		x = rand() % row + 1;     //生成数%row后范围是0~8 我们需要的是1~9,模9余数0到8
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//数周围有几个雷
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return  (mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y]) - (8 * '0');
}
//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = row * col - COUNT_EASY;
	while (win)
	{
		printf("请输入要排查的坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("踩到雷啦！爆炸！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("排查过该坐标，请重新输入\n");
			}
			else if (mine[x][y] == '0')
			{
				int ret = 0;
				ret = GetMineCount(mine, x, y);
				show[x][y] = ret + '0';

				DisplayBoard(show, ROW, COL);
				win--;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	//跳出循环有两种可能，一个是踩雷退出，一个是排雷完成退出
	//需要判断是不是排雷成功，然后给出提示
	if (win == 0)
		printf("恭喜你，排雷成功！ \n");
}
