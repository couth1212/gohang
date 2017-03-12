//���� �� ��

#include <stdio.h>
#include <stdlib.h>

#define N	15

int chessboard[N + 1][N + 1] = { 0 };

//������¼�ֵ����1�������2
int whoseTurn = 0;

void initGame(void);
void printChessboard(void);
void playChess(void);
int judge(int, int);

int main(void)
{
	//��ʼ����Ϸ
	initGame();

	while (1)
	{
		//ÿ��ѭ������1��ʵ�������������
		whoseTurn++;

		playChess();
	}

	return 0;
}

void initGame(void)
{
	char c;

	printf("��ӭ^_^������y������Ϸ��");
	c = getchar();
	if ('y' != c && 'Y' != c)
		exit(0);

	system("clear");
	printChessboard();
}

void printChessboard(void)
{
	int i, j;

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			if (0 == i)
				printf("%3d", j);
			else if (j == 0)
				printf("%3d", i);
			else if (1 == chessboard[i][j])
				printf("  ��");
			else if (2 == chessboard[i][j])
				printf("  ��");
			else
				printf("  *");
		}
		printf("\n");
	}
}

void playChess(void)
{
	int i, j, winner;

	if (1 == whoseTurn % 2)
	{
		printf("�ֵ����1�����������ӵ�λ�ã���ʽΪ�к�+�ո�+�кţ�");
		scanf("%d %d", &i, &j);
		chessboard[i][j] = 1;
	}
	else
	{
		printf("�ֵ����2�����������ӵ�λ�ã���ʽΪ�к�+�ո�+�кţ�");
		scanf("%d %d", &i, &j);
		chessboard[i][j] = 2;
	}

	system("clear");
	printChessboard();
	
	if (judge(i, j))
	{
		if (1 == whoseTurn % 2)
			printf("���1ʤ��\n");
		else
			printf("���2ʤ��\n");
	}
}

int judge(int x, int y)
{
	int i, j;
	int t = 2 - whoseTurn % 2;

	for (i = x - 4, j = y; i <= x; i++)
	{
		if (i >= 1 && i <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j] && t == chessboard[i + 2][j] && t == chessboard[i + 3][j] && t == chessboard[i + 4][j])
			return 1;
	}
	for (i = x, j = y - 4; j <= y; j++)
	{
		if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 1] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
			return 1;
	}
	for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
	{
		if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
			return 1;
	}
	for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
	{
		if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
			return 1;
	}

	return 0;
}