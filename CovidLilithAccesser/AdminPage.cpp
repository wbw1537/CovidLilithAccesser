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

//��Ҫ��ӵĹ�����Ա	
// 0�ɹ� 1��ͻ 2����
int AddVolunteer(volunteer toadd);

//��Ҫɾ���ľ����ID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelResident(long residentID);

//��Ҫɾ���Ĺ�����ԱID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelVolunteer(long volunteerID);