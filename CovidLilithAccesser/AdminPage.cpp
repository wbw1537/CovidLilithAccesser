#include"AdminPage.h"
#pragma warning(disable : 4996)

resident* residentInfo;
//volunteer* volunteerInfo;

void AdminPage()
{
	MOUSEMSG m2;
	AdminPageOpen = 1;

	ADM adminUser;
	rectProperties text1, text2, text3, exitButtonCorr;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	text3 = { 120,120,960,540 };
	exitButtonCorr = { 800,480,860,510,0,1 };

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
	char adminText3[200];
	char exitButtonText[50] = { "退出" };
	sprintf_s(adminText2, 50, "欢迎您，%s", adminUser.name, 20);
	sprintf_s(adminText3, 50, "当前共有社区工作者%d名，用户%d名。", numOfVol, numOfRes);

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
	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);

	DrawTextsSingle(text3, songTi, adminText3, 25, 600, 0, blackOfText);
	do{

		//get the mouce position and operation
		m2 = GetMouseMsg();
		
		CheckButton(m2,messageButton,InfoPage,firstRect,20);
		CheckButton(m2, volButton, VolManageMenu, secendRect, 20);
		CheckButton(m2, resiButton, ReciManageMenu, thirdRect, 20);
		CheckButton(m2, exitButtonCorr, EndAdminButton, exitButtonText, 20);
		/*
		//init the mouce activity to not in
		messageButton.mouceActiv = 0;
		volButton.mouceActiv = 0;
		resiButton.mouceActiv = 0;

		//message button
		

		//vol button
		if (m2.x > volButton.left && m2.y > volButton.top && m2.y < messageButton.right && m2.x > messageButton.buttom) {
			volButton.mouceActiv = 1;
			if (m2.uMsg == WM_LBUTTONDOWN) {
				volButton.mouceActiv = 2;
			}
			if (m2.uMsg == WM_LBUTTONUP) {
				//
			}
		}

		//user button
		if (m2.x > messageButton.left && m2.y > messageButton.top && m2.y < messageButton.right && m2.x > messageButton.buttom) {
			messageButton.mouceActiv = 1;
			if (m2.uMsg == WM_LBUTTONDOWN) {
				messageButton.mouceActiv = 2;
			}
			if (m2.uMsg == WM_LBUTTONUP) {
				//
			}
		}
		*/
	} while (AdminPageOpen);
}

void EndAdminButton() {
	AdminPageOpen = 0;
	LoadLoginPage();
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
	char ch;
	for (int i = 0; i < lines; i++) {
		while (fscanf(fp, "%s", &ch) && ch != '\n') {
			;
		}
	}
}

int AddResident(resident toadd) {

	FILE* fp = { 0 };
	fp = fopen(".\\data\\resinfo", "r");
	long testID = 0;
	while (fscanf(fp, "%*s ,%*s ,%*s ,%ld ,%*s ,%*u ,%*s ,%*d ,%*d", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\resinfo", "a");
	fprintf(fp, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d\n",
		toadd.name, toadd.passwd, toadd.fromProvince, toadd.ID,
		toadd.belong, toadd.building, toadd.district, toadd.ifRead, toadd.ifRisky
	);
	fclose(fp);
	return 0;
}

int AddVolunteer(volunteer toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\volinfo", "r");
	long testID = 0;
	bool have = false;
	while (fscanf(fp, "%*s ,%*s ,%ld ,%*d ,%*d ,%*s ,%*llu ,%*s ,%*s", &testID) == 1) {
		if (testID == toadd.ID) {
			return 1;
		}
	}
	fclose(fp);

	fp = fopen(".\\data\\volinfo", "a");
	fprintf(fp, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n",
		toadd.name, toadd.passwd, toadd.ID, toadd.age, toadd.sex,
		toadd.department, toadd.phone, toadd.wechat, toadd.position
	);
	fclose(fp);
	return 0;
}
	
bool DelResident(long residentID) {
	FILE* fp = { 0 };
	FILE* fpw = { 0 };
	bool del = false;
	fp = fopen(".\\data\\resinfo", "r");
	rewind(fp);
	fpw = fopen(".\\data\\tmp", "w+");
	resident tmp = { 0 };
	while (fscanf_s(fp, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d",
		tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID,
		&tmp.belong, &tmp.building, tmp.district, 32, &tmp.ifRead, &tmp.ifRisky
		) == 9
	) {
		if (tmp.ID != residentID) {
			fprintf(fpw, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d\n",
				tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong,
				tmp.building, tmp.district, tmp.ifRead, tmp.ifRisky
			);
		}
		else {
			del = true;
		}
	}
	fclose(fp);
	fp = fopen(".\\data\\resinfo", "w");
	rewind(fpw);
	while (fscanf_s(fpw, "%s ,%s ,%s ,%d ,%s ,%u ,%s ,%d ,%d",
		tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID,
		&tmp.belong, &tmp.building, tmp.district, 32, &tmp.ifRead, &tmp.ifRisky
		) == 9
	) {
		fprintf(fp, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d\n",
			tmp.name, tmp.passwd, tmp.fromProvince, tmp.ID, tmp.belong,
			tmp.building, tmp.district, tmp.ifRead, tmp.ifRisky
		);
	}
	fclose(fp);
	fclose(fpw);
	return del;
}

bool DelVolunteer(long volunteerID) {
	FILE* fp = { 0 };
	FILE* fpw = { 0 };
	bool del = false;
	fp = fopen(".\\data\\volinfo", "r");
	rewind(fp);
	fpw = fopen(".\\data\\tmp", "w+");
	volunteer tmp = { 0 };
	while (fscanf_s(fp, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s",
		tmp.name, 50, tmp.passwd, 128, &tmp.ID, &tmp.age, &tmp.sex,
		tmp.department, 64, &tmp.phone, tmp.wechat, 64, tmp.position, 32
	) == 9) {
		if (tmp.ID != volunteerID) {
			fprintf(fpw, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n",
				tmp.name, tmp.passwd, tmp.ID, tmp.age, tmp.sex, tmp.department, tmp.phone, tmp.wechat, tmp.position
			);
		}
		else {
			del = true;
		}
	}
	fclose(fp);
	fp = fopen(".\\data\\volinfo", "w");
	rewind(fpw);
	while (fscanf_s(fpw, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s",
		tmp.name, 50, tmp.passwd, 128, &tmp.ID, &tmp.age, &tmp.sex, tmp.department, 64,
		&tmp.phone, tmp.wechat, 64, tmp.position, 32) == 9) {
		fprintf(fp, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n",
			tmp.name, tmp.passwd, tmp.ID, tmp.age, tmp.sex, tmp.department, tmp.phone, tmp.wechat, tmp.position);
	}
	fclose(fp);
	fclose(fpw);
	return del;
}

void SaveInResiModify() {
	FILE* fp;
	fopen_s(&fp, "data/resinfo", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < numOfRes; i++) {
		if (residentInfo[i].ID != 0) {
			fprintf(fp, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d\n",
				residentInfo[i].name, residentInfo[i].passwd, residentInfo[i].fromProvince, residentInfo[i].ID, residentInfo[i].belong,
				residentInfo[i].building, residentInfo[i].district, residentInfo[i].ifRead, residentInfo[i].ifRisky);
		}
		fclose(fp);
	}
}

void SaveInVolModify() {
	FILE* fp;
	fopen_s(&fp, "data/volinfo", "w");
	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < numOfVol; i++) {
		if (volunteerInfo[i].ID != 0) {
			fprintf(fp, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s\n",
				volunteerInfo[i].name, volunteerInfo[i].passwd, volunteerInfo[i].ID, volunteerInfo[i].age, volunteerInfo[i].sex, volunteerInfo[i].department, volunteerInfo[i].phone, volunteerInfo[i].wechat, volunteerInfo[i].position);
		}
		fclose(fp);
	}
}

bool LoadResidentInfoFile() {
	residentInfo = (resident*)malloc(5 * sizeof(resident));
	if (residentInfo == NULL) {
		return false;
	}
	ZeroMemory(residentInfo, 5 * sizeof(resident));
	int size = 5, index = 0;
	resident tmp = { 0 };
	resident* tmpArray;
	FILE* fp = fopen(".\\data\\resinfo", "r");
	while (fscanf_s(fp, "%s ,%s ,%s ,%ld ,%s ,%u ,%s ,%d ,%d",
		tmp.name, 50, tmp.passwd, 128, tmp.fromProvince, 32, &tmp.ID, tmp.belong, 50, 
		&tmp.building, tmp.district, 32, &tmp.ifRead, &tmp.ifRisky) == 9
		) {
		residentInfo[index] = tmp;
		if (index == size - 1) {
			tmpArray = residentInfo;
			residentInfo = (resident*)malloc(2 * size * sizeof(resident));
			if (residentInfo == NULL) {
				return false;
			}
			ZeroMemory(residentInfo, 2 * size * sizeof(resident));
			for (int i = 0; i < size; i++) {
				residentInfo[i] = tmpArray[i];
			}
			size *= 2;
		}
		index++;
		
	}
	numOfRes = index;
	return true;
}


bool LoadVolInfoFile(){
	volunteerInfo = (volunteer*)malloc(5 * sizeof(volunteer));
	if (volunteerInfo == NULL) {
		return false;
	}
	ZeroMemory(volunteerInfo, 5 * sizeof(volunteer));
	int size = 5, index = 0;
	volunteer tmp = { 0 };
	volunteer* tmpArray;
	FILE* fp = fopen(".\\data\\volinfo", "r");
	while (fscanf_s(fp, "%s ,%s ,%ld ,%d ,%d ,%s ,%llu ,%s ,%s",
		tmp.name, 50, tmp.passwd, 128, tmp.ID, 32, &tmp.age, &tmp.sex,
		&tmp.department, tmp.phone, 32, &tmp.wechat, &tmp.position) == 9
		) {
		volunteerInfo[index] = tmp;
		if (index == size - 1) {
			tmpArray = volunteerInfo;
			volunteerInfo = (volunteer*)malloc(2 * size * sizeof(volunteer));
			if (volunteerInfo == NULL) {
				return false;
			}
			ZeroMemory(volunteerInfo, 2 * size * sizeof(volunteer));
			for (int i = 0; i < size; i++) {
				volunteerInfo[i] = tmpArray[i];
			}
			size *= 2;
		}
		index++;
	}
	numOfVol = index;
	return true;
}

