#include "game.h"
#define _CRT_SECURE_NO_WARNINGS

void menu()
{
	printf("*********************************\n");
	printf("*******   ɨ��С��Ϸ    *********\n");
	printf("*******     1��play     *********\n");
	printf("*******     0��exit     *********\n");
	printf("*********************************\n");
}
void game()
{
	//Ϊ�˷��㣬���������鶨�����ȫһ����
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��ʼ���������飬����Ӧ�Ĳ�����ȥ
	//��������ȫ������Ϊ0
	//����ʾ�̶���Ϊ*
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
	//������һ��input�ж�Ҫ��Ҫ������Ϸ������Ҳ��Ϊѭ�����ж�����
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("������->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			//�������1��˵��Ҫ����Ϸ����װһ��game������������Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}