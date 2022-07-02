#include"InfoPage.h"

void InfoPage()
{

}

void ReciManageMenu(){
	MOUSEMSG m3;
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);
	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfRes(10, 10, 80, 40, 20, &residentInfo[1], m3);
		DrawLineButtonOfRes(10, 50, 80, 40, 20, &residentInfo[2], m3);
		DrawLineButtonOfRes(10, 90, 80, 40, 20, &residentInfo[3], m3);
		DrawLineButtonOfRes(10, 130, 80, 40, 20, &residentInfo[4], m3);
		DrawLineButtonOfRes(10, 170, 80, 40, 20, &residentInfo[5], m3);
		DrawLineButtonOfRes(10, 210, 80, 40, 20, &residentInfo[6], m3);
		DrawLineButtonOfRes(10, 250, 80, 40, 20, &residentInfo[7], m3);

		
	} while (1);
}

void VolManageMenu() {
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);

	do {

	} while (1);
}