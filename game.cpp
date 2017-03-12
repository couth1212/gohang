#include<stdio.h>
#include<windows.h>

#define up 'w'
#define left 'a'
#define down 's'
#define right 'd'
#define lz 'p'
#define cls 'q'

struct stu{                              //定义位置记录结构体 
	int x;
	int y;
}weizhi;
int player=1;
int Q[20][20]={0};                       //定义数组记录骡子情况 

void gotoxy(int x,int y)                 //建立坐标函数 
{
	COORD c;
	c.X=2*x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); //修改当前光标位置
}

void drawqipan()                          //绘制棋盘及数据初始化
{
	int i,j;
	system("cls");
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			Q[i][j]=0;
			printf("┼");
		}
		printf("\n");
	}
	weizhi.x=0;weizhi.y=0;                     //数据初始化 
	gotoxy(0,0);
} 

void jilu()                                       //记录落子情况
{
	Q[weizhi.x][weizhi.y]=player+1;
	if(player)
	{
		player=0;                                   //玩家变换 
 		return;
	}
	player=1;
} 
int cluozi(int x,int y)                             //有电脑落子时调用
{
	weizhi.x=x;
	weizhi.y=y;
	gotoxy(weizhi.x,weizhi.y);
	if(Q[weizhi.x][weizhi.y]==0)   					   //判断当前位置是否已经落子 
	{
		jilu();
		printf("○");
		gotoxy(weizhi.x,weizhi.x);
	}
} 
							
void luozi()              				 		    //玩家落子
{
	if(Q[weizhi.x][weizhi.y]==0)           			 //判断当前位置是否已经落子 
	{
		if(player)
		{
			jilu();
			printf("●");
		}
		else
		{
			jilu();
			printf("○");
		}
		gotoxy(weizhi.x,weizhi.y);
	}
}

int CheckWin()      									  //检查游戏是否有输赢
{
	int p;
	int r,rr,c,cc,Count=0;
	p=player==0?2:1;
	for(c=0;c<20;c++)
	{
		for(r=0;r<20;r++)
		{
			if(Q[r][c]!=p)
		 		continue;
		 		       										//检查列
			rr=r;cc=c;
			while(--cc>=0&&Q[rr][cc]==p)
				Count++;cc=c;
			while(++cc<20&&Q[rr][cc]==p)
				Count++;cc=c;
			if(Count+1>=5)
				return p;
															//检查行
			Count=0;
			while(--rr>=0&&Q[rr][cc]==p)
				Count++;rr=r;
			while(++rr<20&&Q[rr][cc]==p)
				Count++;rr=r;
			if(Count+1>=5)
				return p;
															//检查反斜边
			Count=0;
			cc--;rr--;
			while((cc>=0||rr>=0)&&Q[rr][cc]==p)
			{
				Count++;cc--;rr--;
			}
			rr=r;cc=c;cc++;rr++;
			while((cc<20||rr<20)&&Q[rr][cc]==p)
			{
				Count++;cc++;rr--;
			}
			rr=r;cc=c;
			if(Count+1>=5)
				return p;
															//检查正斜边
			Count=0;
			cc++;rr--;
			while((cc<20||rr>=0)&&Q[rr][cc]==p)
			{
				Count++;cc++;rr--;
			}
			rr=r;cc=c;cc--;rr++;
			while((cc>=0||rr<20)&&Q[rr][cc])
			{
				Count++;cc--;rr++;
			}
			rr=r;cc=c;
			if(Count+1>5)
				return p;
			Count=0;	 
		}
	}
	return 0;
} 

void Keypress(char n)       //光标位置移动
{
	switch(n)
	{
		case up:				//向上移动光标 
			if(weizhi.y<=0)
				weizhi.y=19;
			else
				weizhi.y--;
			gotoxy(weizhi.x,weizhi.y);break;

		case left:					//向左移动光标 
			if(weizhi.x<=0)
				weizhi.x=19;
			else
				weizhi.y--;
			gotoxy(weizhi.x,weizhi.y);break;
			
		case right:               //向右移动光标 
			if(weizhi.x>=19)
				weizhi.x=0;
			else
				weizhi.x++;
			gotoxy(weizhi.x,weizhi.y);break;
			
		case down: 						//向下移动光标 
			if(weizhi.y>=19)
				weizhi.y=0;
			else
				weizhi.y++;
			gotoxy(weizhi.x,weizhi.y);break;
		
		case lz: luozi();break;    		//开始落子操作	
		case cls: drawqipan();break;		//重新开始 
	}
} 

int main()
{
	char press;
	int winer=0;
	system("colsr 2f");
l:  drawqipan();
	press=getchar();
	while(1)
	{
		Keypress(press);
		if(press=='p')
			winer=CheckWin(); 
		if(winer!=0)
			gotoxy(0,20);
		if(winer==2)
			printf("the side of ● wins\n");
		else if(winer==1)
			printf("the side of ○ wins\n");
		else
		{
			if(player==0)
			{
				cluozi(1,2);
			}
			press=getchar();
			continue;
		}
	printf("do you want to play again?(y/n)");
p:	press=getchar();
	if(press=='n')
		break;
	else if(press=='y')
	{
		winer==0;
		goto l;
	}
	else
		goto p;
		
	}
	return 0;
}