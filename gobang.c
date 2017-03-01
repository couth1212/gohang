

//五子棋游戏   测试版


#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <bios.h>
#include <conio.h>

#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define SPACE 0x3920

#define BILI 20
#define JZ 4
#define JS 3
#define N 19

int box[N][N];
int step_x,step_y;
int key;
int flag=1;

void attention();

void main()
{
	int gdriver=VGA.gmode=VGAHI;
	clrscr();
	attention();
}

void attention();
{
	char ch;
	window(1,1,80,25);
	textbackground(LIGHTBLUE):
	textcolor(YELLOW);
	clrscr();
	gotoxy(15,2);
	print("游戏规则");
	gotoxy(15,4);
}





























