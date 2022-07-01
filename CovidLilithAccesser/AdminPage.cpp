#include"AdminPage.h"
#pragma warning(disable : 4996)

void AdminPage()
{
	cleardevice();
	IMAGE backGround, logo, title;
	loadimage(&backGround, "resources/backGround.jpg");
	putimage(0, 0, &backGround);
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