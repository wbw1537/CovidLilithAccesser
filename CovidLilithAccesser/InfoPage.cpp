#include"InfoPage.h"
#pragma warning(disable : 4996)
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