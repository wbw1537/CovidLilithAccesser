#include"AdminPage.h"
#pragma warning(disable : 4996)

void AdminPage()
{
	
	ADM adminUser;
	rectProperties text1,text2;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	//read the file to get the login account and passwd.
	FILE* fp;
	fopen_s(&fp, "data/admininfo", "r");
	if (fp == NULL) return;
	fscanf_s(fp, "%s%s%s", adminUser.ID, 64, adminUser.passWd, 64, adminUser.name, 64);
	fclose(fp);
	//init some graphs
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);
	//draw the texts
	char adminText1[50] = { "管理员操作界面:" };
	char adminText2[50];
	sprintf_s(adminText2, 50, "欢迎您，%s", adminUser.name, 20);
	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);
	//button charecters
	char firstRect[30] = { "信息收集与发布" };
	char secendRect[30] = { "工作人员信息列表" };
	char thirdRect[30] = { "用户信息列表" };
	//button rect
	rectProperties messageButton, volButton, resiButton;
	messageButton = { 150,400,150 + 180,400 + 45,0,1 };
	volButton = { 390,400,390 + 180,400 + 45,0,1 };
	resiButton = { 630,400,630 + 180,400 + 45,0,1 };
	//draw the button first
	DrawButton(messageButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, firstRect, 20);
	DrawButton(volButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, secendRect, 20);
	DrawButton(resiButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, thirdRect, 20);
	do
	{

	} while (1);
}
//release info to the resident or volunteer
void ReleaseInfo(int towards) {
	if (towards == 0) { // to resident
		//read the title and info to resident
		char toResiInfoTitle[128], toResiInfoMessage[128];
		TCHAR InputTitle[] = _T("请输入要向居民发布的信息标题");
		InputBox(toResiInfoTitle, 128, InputTitle);
		TCHAR InputMessage[] = _T("请输入要向居民发布的信息内容");
		InputBox(toResiInfoMessage, 128, InputMessage);
		FILE* fp;
		fp = fopen("data/resimessage", "a");
		fprintf(fp, "%s %s", toResiInfoTitle, toResiInfoMessage);
	}
	if (towards == 1) { // to volunteer
		//read the title and info to volunteer
		char toVolInfoTitle[128], toVolInfoMessage[128];
		TCHAR InputTitle[] = _T("请输入要向社区工作者发布的信息标题");
		InputBox(toVolInfoTitle, 128, InputTitle);
		TCHAR InputMessage[] = _T("请输入要向居民发布的信息内容");
		InputBox(toVolInfoMessage, 128, InputMessage);
		FILE* fp;
		fp = fopen("data/volmessage", "a");
		fprintf(fp, "%s %s", toVolInfoTitle, toVolInfoMessage);
	}
}

void JumpLines(int lines, FILE * fp) {
	wchar_t ch;
	for (int i = 0; i < lines; i++) {
		while (fwscanf(fp, L"%c", &ch) && ch != '\n') {
			;
		}
	}
}

int AddResident(resident toadd) {

	FILE* fp = { 0 };
	fp = fopen(".\\data\\resinfo", "r, ccs=utf-8");
	long testID = 0;
	bool have = false;
	while (fwscanf(fp, L"%*s ,%*s ,%*s ,%ld ,%*ld ,%*u ,%*s ,%*d ,%*d", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\resinfo", "a, ccs=utf-8");
	fwprintf(fp, L"%s ,%s ,%s ,%ld ,%ld ,%u ,%s ,%d ,%d\n", toadd.name, toadd.passwd, toadd.fromProvince, toadd.ID, toadd.belong, toadd.building, toadd.district, toadd.ifRead, toadd.ifRisky);
	fclose(fp);
	return 0;
}

int AddVolunteer(volunteer toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\volinfo", "r, ccs=utf-8");
	long testID = 0;
	bool have = false;
	while (fwscanf(fp, L"%*s ,%*s ,%ld ,%*d ,%*d ,%*s ,%*llu ,%*s ,%*s", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\volinfo", "a, ccs=utf-8");
	fwprintf(fp, L"%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n", toadd.name, toadd.passwd, toadd.ID, toadd.age, toadd.sex, toadd.department, toadd.phone, toadd.wechat, toadd.position);
	fclose(fp);
	return 0;
}
	
bool DelResident(long residentID) {
	FILE* fp = { 0 };
	FILE* fpw = { 0 };
	bool del = false;
	fp = fopen(".\\data\\resinfo", "r, ccs=utf-8");
	rewind(fp);
	fpw = fopen(".\\data\\tmp", "w+, ccs=utf-8");
	resident tmp = { 0 };
	while (fwscanf_s(fp, L"%s ,%s ,%s ,%ld ,%ld ,%u ,%s ,%d ,%d", tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID, &tmp.belong, &tmp.building, tmp.district, 32, &tmp.ifRead, &tmp.ifRisky) == 9) {
		if (tmp.ID != residentID) {
			fwprintf(fpw, L"%s ,%s ,%s ,%ld ,%ld ,%u ,%s ,%d ,%d\n", tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong, tmp.building, tmp.district, tmp.ifRead, tmp.ifRisky);
		}
		else {
			del = true;
		}
	}
	fclose(fp);
	fp = fopen(".\\data\\resinfo", "w, ccs=utf-8");
	rewind(fpw);
	while (fwscanf_s(fpw, L"%s ,%s ,%s ,%ld ,%ld ,%u ,%s ,%d ,%d", tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID, &tmp.belong, &tmp.building, tmp.district, 32, &tmp.ifRead, &tmp.ifRisky) == 9) {
		fwprintf(fp, L"%s ,%s ,%s ,%ld ,%ld ,%u ,%s ,%d ,%d\n", tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong, tmp.building, tmp.district, tmp.ifRead, tmp.ifRisky);
	}
	fclose(fp);
	fclose(fpw);
	return del;
}

bool DelVolunteer(long volunteerID) {
	FILE* fp = { 0 };
	FILE* fpw = { 0 };
	bool del = false;
	fp = fopen(".\\data\\volinfo", "r, ccs=utf-8");
	rewind(fp);
	fpw = fopen(".\\data\\tmp", "w+, ccs=utf-8");
	volunteer tmp = { 0 };
	while (fwscanf_s(fp, L"%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s", tmp.name, 50, tmp.passwd, 128, &tmp.ID, &tmp.age, &tmp.sex, tmp.department, 64, &tmp.phone, tmp.wechat, 64, tmp.position, 32) == 9) {
		if (tmp.ID != volunteerID) {
			fwprintf(fpw, L"%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n", tmp.name, tmp.passwd, tmp.ID, tmp.age, tmp.sex, tmp.department, tmp.phone, tmp.wechat, tmp.position);
		}
		else {
			del = true;
		}
	}
	fclose(fp);
	fp = fopen(".\\data\\volinfo", "w, ccs=utf-8");
	rewind(fpw);
	while (fwscanf_s(fpw, L"%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s", tmp.name, 50, tmp.passwd, 128, &tmp.ID, &tmp.age, &tmp.sex, tmp.department, 64, &tmp.phone, tmp.wechat, 64, tmp.position, 32) == 9) {
		fwprintf(fp, L"%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n", tmp.name, tmp.passwd, tmp.ID, tmp.age, tmp.sex, tmp.department, tmp.phone, tmp.wechat, tmp.position);
	}
	fclose(fp);
	fclose(fpw);
	return del;
}