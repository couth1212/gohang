#include <stdio.h>
#include <stdlib.h>

#define n 15
#define N 15

int chessboard[n+1][n+1]={0};           //定义数组记录棋子
int whoseTurn=0;                        //用来记录轮到玩家1还是玩家2，奇数是玩家1，偶数是玩家2；


void initGame();                        //欢迎界面，调用printChessboard();打印棋盘
void playChess();                       //实现落子操作
void printChessboard();                 //打印棋盘函数
int judge(int x,int y,int whoseTurn);


int main()
{
	initGame();                          //自定义函数，用来初始化游戏；显示欢迎界面；显示棋盘
	while(1)
	{
		whoseTurn++;                     //每次循环加1 实现2人轮流
		playChess();                     //定义函数；实现落子操作
	}
	return 0;

}

void initGmame()
{
	char c;
	printf("欢迎 请输入y进入游戏：");
	c=getchar();
	if('Y'!=c&&'y'!=c)
			exit(0);
	system("clear");                      //linux下清屏函数，使用stdlib.h头文件；win下使用system("cls");
	printChessboard();                    //定义函数；打印棋盘

}

void printChessboard()                    //更新绘制棋盘
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(0==i)                       //打印行号
				printf("%3d",j);
			else if(j=0)                   //打印列号
					printf("%3d",i);       
			else if(1==chessboard[i][j])   //play1落子
					printf(" x");
			else if(2==chessboard[i][j])   //play2落子
					printf(" o");
			else
					printf(" *");
		}
		printf("\n");
	}
}

void playChess()                            //落子函数
{
	int i,j,winner;
	if(1==whoseTurn%2)
	{
		printf("轮到玩家1，请输入棋子的位置，格式为行号+空格+列号：");
		scanf("%d %d",&i,&j);
		chessboard[i][j]=1;
	}
	else
	{
		printf("轮到玩家2，请输入棋子的位置，格式为行号+空格+列号：");
		scanf("%d %d",&i,&j);
		chessboard[i][j]=2;
	}
	                                        //重新打印一次棋盘
	system("clear");
	printChessboard();                      //调用打印期盼的函数
	if(judge(i,j,whoseTurn))
	{
		if(1==whoseTurn%2)
				printf("玩家1胜！\n");
		else 
				printf("玩家2胜！\n");
	}
}

int judge(int x,int y,int whoseTurn)
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
		if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 2] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
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
