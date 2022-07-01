#include"CovidLilithAccesser.h"



int main(void)
{
	_wsetlocale(LC_ALL, L"zh_CN.utf-8");
	initgraph(WINDOWWIDTH, WINDOWHEIGHT);
	
	

	//load the login page
	LoadLoginPage();


	system("pause");
	return 0;
}