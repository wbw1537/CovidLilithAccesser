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
		for (int i = 0; i < numOfRes; i++){
			DrawLineButtonOfRes(10, 10, 80, 40, 20, &residentInfo[i], m3);
		}
		
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