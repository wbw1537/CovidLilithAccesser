#include"CovidLilithAccesser.h"


int main(void)
{
	_wsetlocale(LC_ALL, L"zh_CN.utf-8");

	
	if (!LoadVolInfoFile()) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�ڴ�ռ�������", "����", MB_OK);
	}
	
	if (!LoadResidentInfoFile()) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�ڴ�ռ�������", "����", MB_OK);
	}
	
	initgraph(WINDOWWIDTH, WINDOWHEIGHT);
	
	//load the login page
	LoadLoginPage();


	system("pause");
	return 0;
}