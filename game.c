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
	printf("--------ɨ��---------\n");
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
//������
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = COUNT_EASY;  //�׵�����
	while (count)//��û��������֮ǰ������ѭ��
	{
		x = rand() % row + 1;     //������%row��Χ��0~8 ������Ҫ����1~9,ģ9����0��8
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//����Χ�м�����
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
//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = row * col - COUNT_EASY;
	while (win)
	{
		printf("������Ҫ�Ų������->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�ȵ���������ը��\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("�Ų�������꣬����������\n");
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
			printf("��������Ƿ�������������\n");
		}
	}
	//����ѭ�������ֿ��ܣ�һ���ǲ����˳���һ������������˳�
	//��Ҫ�ж��ǲ������׳ɹ���Ȼ�������ʾ
	if (win == 0)
		printf("��ϲ�㣬���׳ɹ��� \n");
}
