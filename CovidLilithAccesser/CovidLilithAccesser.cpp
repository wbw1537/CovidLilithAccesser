#include"CovidLilithAccesser.h"


int main(void)
{
	_wsetlocale(LC_ALL, L"zh_CN.utf-8");

	if (!LoadVolInfoFile()) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}
	
	if (!LoadResidentInfoFile()) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}

	if (!ReadMessageFile(VolToResiMessageList,2,numOfVolToResiMessage)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}

	if (!ReadMessageFile(AdminToVOlMessageList,1, numOfAdminToVolMessage)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}

	if (!ReadMessageFile(VolToAdminMessageList, 3, numOfVolToAdminMessage)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}

	if (!ReadMessageFile(ResiToVolMessageList, 4, numOfResiToVolMessage)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "内存空间分配错误", "警告", MB_OK);
	}
	
	initgraph(WINDOWWIDTH, WINDOWHEIGHT);
	
	//load the login page
	LoadLoginPage();


	system("pause");

	free(residentInfo);
	free(volunteerInfo);
	free(VolToResiMessageList);
	free(ResiToVolMessageList);
	free(VolToAdminMessageList);
	free(AdminToVOlMessageList);
	return 0;
}