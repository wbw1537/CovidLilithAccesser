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
	char adminText1[50] = { "����Ա��������" };
	char adminText2[50];
	sprintf_s(adminText2, "��ӭ����%d", adminUser.name);
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

//��Ҫ��ӵĹ�����Ա	
// 0�ɹ� 1��ͻ 2����
int AddVolunteer(volunteer toadd);

//��Ҫɾ���ľ����ID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelResident(long residentID);

//��Ҫɾ���Ĺ�����ԱID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelVolunteer(long volunteerID);