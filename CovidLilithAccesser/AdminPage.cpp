#include"AdminPage.h"
#pragma warning(disable : 4996)

void AdminPage()
{
	
	ADM adminUser;
	rectProperties text1,text2;
	text1 = { 60,50,500,100 };
	text2 = { 60,90,500,200 };
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
	
	while (1)
	{
		
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
	while (fwscanf(fp, L"%*s ,%*s ,%*s ,%ld ,%*ld ,%*d ,%*d", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\resinfo", "a, ccs=utf-8");
	fwprintf(fp, L"%s ,%s ,%s ,%ld ,%ld ,%d ,%d\n", toadd.name, toadd.passwd, toadd.fromProvince, toadd.ID, toadd.belong, toadd.ifRead, toadd.ifRisky);
	fclose(fp);
	return 0;
}

int AddVolunteer(volunteer toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\volinfo", "r, ccs=utf-8");
	if (fp == NULL) {
		return 2;
	}
	long testID = 0;
	bool have = false;
	while (fwscanf(fp, L"%*s,%*s,%ld", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\vlinfo", "a, ccs=utf-8");
	fwprintf(fp, L"%s,%s,%ld\n", toadd.name, toadd.passwd, toadd.ID);
	return 0;
}

//需要删除的居民的ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelResident(long residentID) {
	FILE* fp = { 0 };
	FILE* fpw = { 0 };
	bool del = false;
	fp = fopen(".\\data\\resinfo", "r, ccs=utf-8");
	rewind(fp);
	fpw = fopen(".\\data\\tmp", "w+, ccs=utf-8");
	resident tmp = { 0 };
	while (fwscanf_s(fp, L"%s ,%s ,%s ,%ld ,%ld ,%d ,%d", tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID, &tmp.belong, &tmp.ifRead, &tmp.ifRisky) == 7) {
		if (tmp.ID != residentID) {
			fwprintf(fpw, L"%s ,%s ,%s ,%ld ,%ld ,%d ,%d\n", tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong, tmp.ifRead, tmp.ifRisky);
		}
		else {
			del = true;
		}
	}
	fclose(fp);
	fp = fopen(".\\data\\resinfo", "w, ccs=utf-8");
	rewind(fpw);
	while (fwscanf_s(fpw, L"%s ,%s ,%s ,%ld ,%ld ,%d ,%d", tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID, &tmp.belong, &tmp.ifRead, &tmp.ifRisky) == 7) {
		fwprintf(fp, L"%s ,%s ,%s ,%ld ,%ld ,%d ,%d\n", tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong, tmp.ifRead, tmp.ifRisky);
	}
	fclose(fp);
	fclose(fpw);
	return del;
}

//需要删除的工作人员ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelVolunteer(long volunteerID);