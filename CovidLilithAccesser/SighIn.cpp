#include"SighIn.h"


ADM adminUser;

void AdminSighIn()
{
	//read the file to get the login account and passwd.
	FILE * fp;
	fopen_s(&fp, "data/admininfo", "r");
	if (fp == NULL) return;
	fscanf_s(fp, "%s%s%s", adminUser.ID, 64, adminUser.passWd, 64, adminUser.name, 64);
	fclose(fp);

	//record the id and passwd received from the box
	char recAcntId[64],recAcntPasswd[64];
	TCHAR InputAcct[] = _T("���������Ա�˺�");
	InputBox(recAcntId, 20, InputAcct);
	TCHAR InputPass[] = _T("����������");
	InputBox(recAcntPasswd, 20, InputPass);

	//check if the ID and passwd received right
	if (!strcmp(adminUser.ID, recAcntId) && !strcmp(adminUser.passWd, recAcntPasswd)){
		loadLoginPageOpen = 0;
		cleardevice();
		AdminPage();
		return;
	}
	else{
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�û������������!", "��ʾ", MB_OK);
		return;
	}
}

void UserSignIn(){

}

void VolSignIn() {

}
