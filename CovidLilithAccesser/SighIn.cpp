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
	TCHAR InputAcct[] = _T("请输入管理员账号：");
	InputBox(recAcntId, 20, InputAcct);
	TCHAR InputPass[] = _T("请输入密码：");
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
		int isok = MessageBox(SignError, "用户名或密码错误!", "提示", MB_OK);
		return;
	}
}

void UserSignIn(){
	char resInputID[64], resInputPasswd[64];
	TCHAR InputAcct[] = _T("请输入账号：");
	InputBox(resInputID, 20, InputAcct);
	bool foundID = 0;
	int returnID = strtol(resInputID, NULL, 10);
	for (int i = 0; i < numOfRes; i++) {
		if (residentInfo[i].ID == returnID) {
			TCHAR InputPasswd[] = _T("请输入密码：");
			InputBox(resInputPasswd, 20, InputPasswd);
			foundID = 1;
			if (!strcmp(resInputPasswd, residentInfo[i].passwd)) {
				nowLoginResi = residentInfo[i];
				loadLoginPageOpen = 0;
				ResiPage();
			}
			else {
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "用户名或密码错误！", "提示", MB_OK);
			}
			break;
		}
	}
	if (!foundID) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "账号不存在，是否注册账号？", "提示", MB_OKCANCEL);
		if (isok == IDOK) {
			resident resInfo;
			char resName[128], resPasswd[128], resFromProvince[128],
				resBelong[128], resBuilding[128], resDistrict[128], resIfRisky[128];
			TCHAR InputName[] = _T("请输入姓名");
			InputBox(resName, 128, InputName);
			TCHAR InputPAsswd[] = _T("请输入密码");
			InputBox(resPasswd, 128, InputPAsswd);
			TCHAR InputProv[] = _T("请输入来源地");
			InputBox(resFromProvince, 128, InputProv);
			TCHAR InputBelong[] = _T("请输入所属工作人员");
			InputBox(resBelong, 128, InputBelong);
			TCHAR InputBuilding[] = _T("请输入居住楼栋");
			InputBox(resBuilding, 128, InputBuilding);
			TCHAR InputDistrict[] = _T("请输入辖区");
			InputBox(resDistrict, 128, InputDistrict);
			TCHAR InputIfRisky[] = _T("请输入风险等级");
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
	TCHAR InputAcct[] = _T("请输入账号：");
	InputBox(volInputID, 20, InputAcct);
	int returnVolID = strtol(volInputID, NULL, 10);
	bool foundID = 0;
	for (int i = 0; i < numOfVol; i++) {
		if (volunteerInfo[i].ID == returnVolID) {
			TCHAR InputPasswd[] = _T("请输入密码：");
			InputBox(volInputPasswd, 20, InputPasswd);
			foundID = 1;
			if (!strcmp(volInputPasswd, volunteerInfo[i].passwd)) {
				nowLoginVol = volunteerInfo[i];
				loadLoginPageOpen = 0;
				VolPage();
			}
			else {
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "用户名或密码错误！", "提示", MB_OK);
			}
			break;
		}
	}
	if (!foundID) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "未找到账号，请重新输入！", "提示", MB_OK);
	}
}
