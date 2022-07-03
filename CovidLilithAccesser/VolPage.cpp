#include"VolPage.h"

void VolPage() {
	MOUSEMSG m4;
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);

	VolPageOpen = 1;

	rectProperties text1, text2, text3, exitButtonCorr;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	text3 = { 180,180,960,540 };
	exitButtonCorr = { 800,480,860,510,0,1 };

	char adminText1[50] = { "社区工作者操作界面:" };
	char adminText2[50];
	char adminText3[200];
	char exitButtonText[50] = { "退出" };
	sprintf_s(adminText2, 50, "欢迎您，%s", nowLoginVol.name, 20);
	sprintf_s(adminText3, 50, "当前共有社区工作者%d名，用户%d名。", numOfVol, numOfRes);


	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);
	DrawTextsSingle(text3, songTi, adminText3, 25, 600, 0, blackOfText);

	char firstRect[30] = { "信息收集与发布" };
	char secendRect[30] = { "用户信息列表" };
	
	//button rect
	rectProperties messageButton, volButton, resiButton;
	messageButton = { 150,400,150 + 180,400 + 45,0,1 };
	resiButton = { 630,400,630 + 180,400 + 45,0,1 };

	DrawButton(messageButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, firstRect, 20);
	DrawButton(resiButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, secendRect, 20);
	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);





	do {

		m4 = GetMouseMsg();

		CheckButton(m4, resiButton, ReciManageMenuForVol, secendRect, 20);
		CheckButton(m4, exitButtonCorr, ExitVolPage, exitButtonText, 20);

	} while (VolPageOpen);
}

void ExitVolPage() {
	VolPageOpen = 0;
	LoadLoginPage();
}