#include"InfoPage.h"
#pragma warning(disable : 4996)
void InfoPage()
{

}

void ReciManageMenu(){
	MOUSEMSG m3;
	ResiManagePageOpen = 1;
	//print background
	cleardevice();
	IMAGE backGround, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&title, "resources/title.png", 290, 109);
	putimage(0, 0, &backGround);
	drawAlpha(&title, 630, 30);

	//print texts
	rectProperties text1, text2, exitButtonCorr;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	exitButtonCorr = { 800,480,860,510,0,1 };
	char adminText1[50] = { "用户信息管理系统:" };
	char adminText2[50] = {"点击各个单元格可修改单元格内容"};
	char exitButtonText[50] = { "退出" };
	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);

	//print sheet
	int leftCoor = 22, topCoor = 170, rectWidth = 115, rectHeight = 30;
	
	rectProperties rects0[20];
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
		rects0[i] = { tempLeftCoor,tempTopCoor - 1 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 0 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
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

	char outputText1[10][50] = { "姓名","用户密码","来源地","编号","所属","楼栋","辖区","风险等级" };
	
	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);

	//output the title of the sheet
	for (int i = 0; i < 8; i++) {
		DrawButton(rects0[i], colorOfBackGround, colorOfBackGround, colorOfBackGround, outputText1[i], 20);
	}
	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfRes(rects1, 15, &residentInfo[0], m3);
		DrawLineButtonOfRes(rects2, 15, &residentInfo[1], m3);
		DrawLineButtonOfRes(rects3, 15, &residentInfo[2], m3);
		DrawLineButtonOfRes(rects4, 15, &residentInfo[3], m3);
		DrawLineButtonOfRes(rects5, 15, &residentInfo[4], m3);
		DrawLineButtonOfRes(rects6, 15, &residentInfo[5], m3);
		DrawLineButtonOfRes(rects7, 15, &residentInfo[6], m3);
		DrawLineButtonOfRes(rects8, 15, &residentInfo[7], m3);
		DrawLineButtonOfRes(rects9, 15, &residentInfo[8], m3);
		
		CheckButton(m3, exitButtonCorr, EndResiManageMenu, exitButtonText, 20);
		
	} while (ResiManagePageOpen);
}

void EndResiManageMenu(){
	ResiManagePageOpen = 0;
	AdminPage();
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
bool WriteVolMessageFile(TextExchange toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\resimessage", "a, ccs=utf-8");
	fwprintf(fp, L"%d ,%d ,%s ,%s ,%s\n", toadd.messageType, toadd.isSolve, toadd.title, toadd.message, toadd.reply);
	fclose(fp);
	return 0;
}
bool WriteResMessageFile(TextExchange toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\resimessage", "a, ccs=utf-8");
	fwprintf(fp, L"%d ,%d ,%s ,%s ,%s\n", toadd.messageType, toadd.isSolve, toadd.title, toadd.message, toadd.reply);
	fclose(fp);
	return 0;
}
bool ReadVolMessageFile() {
	volMessageList = (TextExchange*)malloc(5 * sizeof(TextExchange));
	ZeroMemory(residentInfo, 5 * sizeof(TextExchange));
	int size = 5, index = 0;
	TextExchange tmp = { 0 };
	TextExchange* tmpArray;
	FILE* fp = fopen(".\\data\\volmessage", "r, ccs=utf-8");
	while (fwscanf_s(fp, L"%d ,%d ,%s ,%s ,%s",
		&tmp.messageType, &tmp.isSolve, tmp.title, 500, tmp.message, 500, tmp.reply, 500) == 5
		) {
		volMessageList[index] = tmp;
		if (index == size - 1) {
			tmpArray = volMessageList;
			volMessageList = (TextExchange*)malloc(2 * size * sizeof(TextExchange));
			if (volMessageList == NULL) return false;
			ZeroMemory(volMessageList, 2 * size * sizeof(TextExchange));
			for (int i = 0; i < size; i++) {
				volMessageList[i] = tmpArray[i];
			}
			size *= 2;
		}
		index++;
	}
	return true;
}
bool ReadResMessageFile() {
	resMessageList = (TextExchange*)malloc(5 * sizeof(TextExchange));
	ZeroMemory(residentInfo, 5 * sizeof(TextExchange));
	int size = 5, index = 0;
	TextExchange tmp = { 0 };
	TextExchange* tmpArray;
	FILE* fp = fopen(".\\data\\resimessage", "r, ccs=utf-8");
	while (fwscanf_s(fp, L"%d ,%d ,%s ,%s ,%s",
		&tmp.messageType, &tmp.isSolve, tmp.title, 500, tmp.message, 500, tmp.reply, 500) == 5
		) {
		resMessageList[index] = tmp;
		if (index == size - 1) {
			tmpArray = resMessageList;
			resMessageList = (TextExchange*)malloc(2 * size * sizeof(TextExchange));
			if (resMessageList == NULL) return false;
			ZeroMemory(resMessageList, 2 * size * sizeof(TextExchange));
			for (int i = 0; i < size; i++) {
				resMessageList[i] = tmpArray[i];
			}
			size *= 2;
		}
		index++;
	}
	return true;
}