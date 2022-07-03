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
	TCHAR InputAcct[] = _T("���������Ա�˺ţ�");
	InputBox(recAcntId, 20, InputAcct);
	TCHAR InputPass[] = _T("���������룺");
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
	char resInputID[64], resInputPasswd[64];
	TCHAR InputAcct[] = _T("�������˺ţ�");
	InputBox(resInputID, 20, InputAcct);
	bool foundID = 0;
	int returnID = strtol(resInputID, NULL, 10);
	for (int i = 0; i < numOfRes; i++) {
		if (residentInfo[i].ID == returnID) {
			TCHAR InputPasswd[] = _T("���������룺");
			InputBox(resInputPasswd, 20, InputPasswd);
			foundID = 1;
			if (!strcmp(resInputPasswd, residentInfo[i].passwd)) {
				nowLoginResi = residentInfo[i];
				loadLoginPageOpen = 0;
				ResiPage();
			}
			else {
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "�û������������", "��ʾ", MB_OK);
			}
			break;
		}
	}
	if (!foundID) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�˺Ų����ڣ��Ƿ�ע���˺ţ�", "��ʾ", MB_OKCANCEL);
		if (isok == IDOK) {
			resident resInfo;
			char resName[128], resPasswd[128], resFromProvince[128],
				resBelong[128], resBuilding[128], resDistrict[128], resIfRisky[128];
			TCHAR InputName[] = _T("����������");
			InputBox(resName, 128, InputName);
			TCHAR InputPAsswd[] = _T("����������");
			InputBox(resPasswd, 128, InputPAsswd);
			TCHAR InputProv[] = _T("��������Դ��");
			InputBox(resFromProvince, 128, InputProv);
			TCHAR InputBelong[] = _T("����������������Ա");
			InputBox(resBelong, 128, InputBelong);
			TCHAR InputBuilding[] = _T("�������ס¥��");
			InputBox(resBuilding, 128, InputBuilding);
			TCHAR InputDistrict[] = _T("������Ͻ��");
			InputBox(resDistrict, 128, InputDistrict);
			TCHAR InputIfRisky[] = _T("��������յȼ�");
			InputBox(resIfRisky, 128, InputIfRisky);
			strcpy_s(resInfo.name, resName);
			strcpy_s(resInfo.passwd, resPasswd);
			strcpy_s(resInfo.fromProvince, resFromProvince);
			resInfo.ID = strtol(resInputID, NULL, 10);
			strcpy_s(resInfo.belong, resBelong);
			resInfo.building = strtol(resBuilding, NULL, 10);
			strcpy_s(resInfo.district, resDistrict);
			resInfo.ifRisky = strtol(resIfRisky, NULL, 10);
			resInfo.ifRead = 0;
			AddResident(resInfo);
			LoadResidentInfoFile();
			nowLoginResi = resInfo;
			loadLoginPageOpen = 0;
			ResiPage();
		}
		if (isok == IDCANCEL) {
			return;
		}
	}
}

void VolSignIn() {
	char volInputID[64], volInputPasswd[64];
	TCHAR InputAcct[] = _T("�������˺ţ�");
	InputBox(volInputID, 20, InputAcct);
	int returnVolID = strtol(volInputID, NULL, 10);
	bool foundID = 0;
	for (int i = 0; i < numOfVol; i++) {
		if (volunteerInfo[i].ID == returnVolID) {
			TCHAR InputPasswd[] = _T("���������룺");
			InputBox(volInputPasswd, 20, InputPasswd);
			foundID = 1;
			if (!strcmp(volInputPasswd, volunteerInfo[i].passwd)) {
				nowLoginVol = volunteerInfo[i];
				loadLoginPageOpen = 0;
				VolPage();
			}
			else {
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "�û������������", "��ʾ", MB_OK);
			}
			break;
		}
	}
	if (!foundID) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "δ�ҵ��˺ţ����������룡", "��ʾ", MB_OK);
	}
}
