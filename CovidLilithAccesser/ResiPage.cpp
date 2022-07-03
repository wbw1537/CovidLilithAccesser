#include"ResiPage.h"

void ResiPage() {
	MOUSEMSG m3;
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);

	ResiPageOpen = 1;

	rectProperties text1, text2, text3, exitButtonCorr;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	text3 = { 120,120,960,540 };
	exitButtonCorr = { 800,480,860,510,0,1 };

	char adminText1[50] = { "�û���������:" };
	char adminText2[50];
	char adminText3[200];
	char exitButtonText[50] = { "�˳�" };
	sprintf_s(adminText2, 50, "��ӭ����%s", nowLoginResi.name, 20);

	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);

	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);
	
	
	do {
		m3 = GetMouseMsg();

		CheckButton(m3, exitButtonCorr, ExitResiPage, exitButtonText, 20);

	} while (ResiPageOpen);

}

void ExitResiPage() {
	ResiPageOpen = 0;
	LoadLoginPage();
}