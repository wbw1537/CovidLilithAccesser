#include"AdminPage.h"

void AdminPage()
{
	IMAGE backGround, logo, title;
	loadimage(&backGround, "resources/backGround.jpg");
	putimage(0, 0, &backGround);
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
	fopen(".\\data\\resinfo", "r");

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