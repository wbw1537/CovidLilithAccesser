#include"AdminPage.h"
#pragma warning(disable : 4996)

void AdminPage()
{
	ADM adminUser;
	rectProperties text1,text2;
	text1 = { 10,10,300,100 };
	text2 = { 10,100,100,200 };
	//read the file to get the login account and passwd.
	FILE* fp;
	fopen_s(&fp, "resources\\AdminSignIn", "r");
	if (fp == NULL) return;
	fscanf_s(fp, "%s%s%s", adminUser.ID, 64, adminUser.passWd, 64, adminUser.name, 64);
	fclose(fp);
	//init some graphs
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png");
	putimage(0, 0, &backGround);
	drawAlpha(&title, 550, 30);
	//draw the texts
	char adminText1[50] = { "管理员操作界面" };
	char adminText2[50];
	sprintf_s(adminText2, "欢迎您，%d", adminUser.name);
	DrawTextsSingle(text1, songTi, adminText1, 35, 600, 0, blueOfText);
	while (1)
	{
		
	}
}

void JumpLines(int lines, FILE * fp) {
	int i = 0;
	for (; i < lines; i++) {
		char ch;
		while ((ch = fgetc(fp) != '\n')) {
			;
		}
	}
}

int AddResident(resident toadd) {
	
	FILE* fp = { 0 };
	fp = fopen( ".\\data\\resinfo", "a");
	fprintf(fp, "%s,%s,%ld,%s,%d,%d", toadd.name, toadd.passwd, toadd.ID, toadd.fromProvince, toadd.ifRead, toadd.ifRisky);
	return 0;
}

//需要添加的工作人员	
// 0成功 1冲突 2其他
int AddVolunteer(volunteer toadd);

//需要删除的居民的ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelResident(long residentID);

//需要删除的工作人员ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelVolunteer(long volunteerID);