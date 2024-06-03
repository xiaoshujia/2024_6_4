#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdlib.h>   //srand函数的头文件
#include<time.h>     //time函数的头文件
#define ROW 9    //实际使用的行
#define COL 9    //实际使用的列

#define ROWS 11    //数组使用的行
#define COLS 11    //数组使用的列

#define COUNT_EASY 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);