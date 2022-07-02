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

	int leftCoor = 22, topCoor = 170, rectWidth = 115, rectHeight = 30;
	
	rectProperties rects1[20];
	rectProperties rects2[20];
	rectProperties rects3[20];
	rectProperties rects4[20];
	rectProperties rects5[20];
	rectProperties rects6[20];
	rectProperties rects7[20];
	rectProperties rects8[20];
	rectProperties rects9[20];
	
	int tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects1[i] = { tempLeftCoor,tempTopCoor + 0 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 1*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects2[i] = { tempLeftCoor,tempTopCoor + 1 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 2*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects3[i] = { tempLeftCoor,tempTopCoor + 2 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 3*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects4[i] = { tempLeftCoor,tempTopCoor + 3 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 4*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects5[i] = { tempLeftCoor,tempTopCoor + 4 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 5*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects6[i] = { tempLeftCoor,tempTopCoor + 5 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 6*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects7[i] = { tempLeftCoor,tempTopCoor + 6 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 7*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects8[i] = { tempLeftCoor,tempTopCoor + 7 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 8*rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects9[i] = { tempLeftCoor,tempTopCoor + 8 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 9 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}

	
	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfRes(rects1, 20, &residentInfo[0], m3);
		DrawLineButtonOfRes(rects2, 20, &residentInfo[1], m3);
		DrawLineButtonOfRes(rects3, 20, &residentInfo[2], m3);
		DrawLineButtonOfRes(rects4, 20, &residentInfo[3], m3);
		DrawLineButtonOfRes(rects5, 20, &residentInfo[4], m3);
		DrawLineButtonOfRes(rects6, 20, &residentInfo[5], m3);
		DrawLineButtonOfRes(rects7, 20, &residentInfo[6], m3);
		DrawLineButtonOfRes(rects8, 20, &residentInfo[7], m3);
		DrawLineButtonOfRes(rects9, 20, &residentInfo[8], m3);

		
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