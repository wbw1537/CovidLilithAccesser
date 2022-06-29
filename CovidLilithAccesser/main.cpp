#include<graphics.h>
#include<conio.h>

int main(void)
{
	initgraph(660, 200);
	circle(200, 200, 100);
	_getch();
	closegraph();
	return 0;
}