#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct stu
{
	int x;
	int y;
}weizhi;

void gotoxy(int x,int y)
{
	COORD c;
	c.X=2*x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
	printf("input:");
	scanf("%d%d",&weizhi.x,&weizhi.y);
	printf("output:%d %d\n",weizhi.x,weizhi.y);
	printf("heljdla");
	system("cls");
	gotoxy(weizhi.x,weizhi.y);
	printf("hello");
	return 0;
}