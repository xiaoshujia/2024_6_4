#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdlib.h>   //srand������ͷ�ļ�
#include<time.h>     //time������ͷ�ļ�
#define ROW 9    //ʵ��ʹ�õ���
#define COL 9    //ʵ��ʹ�õ���

#define ROWS 11    //����ʹ�õ���
#define COLS 11    //����ʹ�õ���

#define COUNT_EASY 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);