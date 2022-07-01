#include"AdminPage.h"
#pragma warning(disable : 4996)

void AdminPage()
{
	cleardevice();
	IMAGE backGround, logo, title;
	loadimage(&backGround, "resources/backGround.jpg");
	putimage(0, 0, &backGround);
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
	while (fwscanf(fp, L"%*s,%*s,%ld,%*s,%*d,%*d", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\resinfo", "a, ccs=utf-8");
	fwprintf(fp, L"%s,%s,%ld,%s,%d,%d\n", toadd.name, toadd.passwd, toadd.ID, toadd.fromProvince, toadd.ifRead, toadd.ifRisky);
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

}

//需要删除的工作人员ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelVolunteer(long volunteerID);