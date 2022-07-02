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
	rectProperties text1, text2;
	text1 = { 60,45,500,100 };
	text2 = { 60,85,500,200 };
	
	char adminText1[50] = { "�û���Ϣ����ϵͳ:" };
	char adminText2[50] = {"���������Ԫ����޸ĵ�Ԫ������"};

	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);
	


	rectProperties exitButtonCorr, nextPageButtonCorr, lastPageButtonCorr;
	rectProperties addUserInfoCorr, delUserInfoCorr, reWriteUserInfoCorr;
	int downLeftCorr = 100, downTopCorr = 470, downButtonWidth = 120, downButtonHeight = 40;
	//int tempDownLeftCorr = downLeftCorr;

	addUserInfoCorr = { downLeftCorr,downTopCorr,downLeftCorr + 1 * downButtonWidth + 0 * 10,downTopCorr + downButtonHeight,0,1 };
	delUserInfoCorr = { downLeftCorr + 1 * downButtonWidth + 1 * 10,downTopCorr,downLeftCorr + 2 * downButtonWidth + 1 * 10,downTopCorr + downButtonHeight,0,1 };
	reWriteUserInfoCorr = { downLeftCorr + 2 * downButtonWidth + 2 * 10,downTopCorr,downLeftCorr + 3 * downButtonWidth + 2 * 10,downTopCorr + downButtonHeight,0,1 };
	lastPageButtonCorr = { downLeftCorr + 3 * downButtonWidth + 3 * 10,downTopCorr,downLeftCorr + 4 * downButtonWidth + 3 * 10,downTopCorr + downButtonHeight,0,1 };
	nextPageButtonCorr = { downLeftCorr + 4 * downButtonWidth + 4 * 10,downTopCorr,downLeftCorr + 5 * downButtonWidth + 4 * 10,downTopCorr + downButtonHeight,0,1 };
	exitButtonCorr = { downLeftCorr + 5 * downButtonWidth + 5 * 10,downTopCorr,downLeftCorr + 6 * downButtonWidth + 5 * 10,downTopCorr + downButtonHeight,0,1 };


	char exitButtonText[50] = { "�˳�" };
	char nextPageButtonText[50] = { "����" };
	char lastPageButtonText[50] = { "����" };
	char addUserInfoText[50] = { "����û�" };
	char delUserInfoText[50] = { "ɾ���û�" };
	char reWriteUserInfoText[50] = { "��д�ļ�" };

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

	char outputText1[10][50] = { "����","�û�����","��Դ��","���","����","¥��","Ͻ��","���յȼ�" };
	
	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);
	DrawButton(lastPageButtonCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, lastPageButtonText, 20);
	DrawButton(nextPageButtonCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, nextPageButtonText, 20);
	DrawButton(addUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, addUserInfoText, 20);
	DrawButton(delUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, delUserInfoText, 20);
	DrawButton(reWriteUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, reWriteUserInfoText, 20);




	//output the title of the sheet
	for (int i = 0; i < 8; i++) {
		DrawButton(rects0[i], colorOfBackGround, colorOfBackGround, colorOfBackGround, outputText1[i], 20);
	}

	indexToDrawPage = 0;

	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfRes(rects1, 15, &residentInfo[indexToDrawPage + 0], m3);
		DrawLineButtonOfRes(rects2, 15, &residentInfo[indexToDrawPage + 1], m3);
		DrawLineButtonOfRes(rects3, 15, &residentInfo[indexToDrawPage + 2], m3);
		DrawLineButtonOfRes(rects4, 15, &residentInfo[indexToDrawPage + 3], m3);
		DrawLineButtonOfRes(rects5, 15, &residentInfo[indexToDrawPage + 4], m3);
		DrawLineButtonOfRes(rects6, 15, &residentInfo[indexToDrawPage + 5], m3);
		DrawLineButtonOfRes(rects7, 15, &residentInfo[indexToDrawPage + 6], m3);
		DrawLineButtonOfRes(rects8, 15, &residentInfo[indexToDrawPage + 7], m3);
		DrawLineButtonOfRes(rects9, 15, &residentInfo[indexToDrawPage + 8], m3);
		
		lastIndexToDrawPage = indexToDrawPage;
		forceToFlashButton = 0;

		CheckButton(m3, exitButtonCorr, EndResiManageMenu, exitButtonText, 20);
		CheckButton(m3, nextPageButtonCorr, NextPageButton, nextPageButtonText, 20);
		CheckButton(m3, lastPageButtonCorr, LastPageButton, lastPageButtonText, 20);
		CheckButton(m3, addUserInfoCorr, AddResidentFront, addUserInfoText, 20);
		CheckButton(m3, delUserInfoCorr, DelResidentFront, delUserInfoText, 20);
		CheckButton(m3, reWriteUserInfoCorr, ReWriteResFront, reWriteUserInfoText, 20);
	
	} while (ResiManagePageOpen);
}

void NextPageButton() {
	if (indexToDrawPage < numOfRes) {
		indexToDrawPage++;
	}
	else {
		return;
	}
}
void LastPageButton() {
	if (indexToDrawPage > 0) {
		indexToDrawPage--;
	}
	else return;
}

void AddResidentFront() {
	resident residentInfo;
	char resName[128], resPasswd[128], resFromProvince[128], resID[128], 
		resBelong[128], resBuilding[128], resDistrict[128], resIfRisky[128];
	TCHAR InputName[] = _T("����������");
	InputBox(resName, 128, InputName);
	TCHAR InputPAsswd[] = _T("����������");
	InputBox(resPasswd, 128, InputPAsswd);
	TCHAR InputProv[] = _T("��������Դ��");
	InputBox(resFromProvince, 128, InputProv);
	TCHAR InputID[] = _T("��������");
	InputBox(resID, 128, InputID);
	TCHAR InputBelong[] = _T("����������������Ա");
	InputBox(resBelong, 128, InputBelong);
	TCHAR InputBuilding[] = _T("�������ס¥��");
	InputBox(resBuilding, 128, InputBuilding);
	TCHAR InputDistrict[] = _T("������Ͻ��");
	InputBox(resDistrict, 128, InputDistrict);
	TCHAR InputIfRisky[] = _T("��������յȼ�");
	InputBox(resIfRisky, 128, InputIfRisky);
	strcpy_s(residentInfo.name, resName);
	strcpy_s(residentInfo.passwd, resPasswd);
	strcpy_s(residentInfo.fromProvince, resFromProvince);
	residentInfo.ID = strtol(resID, NULL, 10);
	strcpy_s(residentInfo.belong, resBelong);
	residentInfo.building = strtol(resBuilding, NULL, 10);
	strcpy_s(residentInfo.district, resDistrict);
	residentInfo.ifRisky = strtol(resIfRisky, NULL, 10);
	residentInfo.ifRead = 0;
	if (AddResident(residentInfo)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�ñ���Ѿ����ڣ����������", "��ʾ", MB_OK);
	}
	LoadResidentInfoFile();
	forceToFlashButton = 1;
}

void DelResidentFront(){
	char toDelResID[64];
	TCHAR InputID[] = _T("������Ҫɾ�����û����");
	InputBox(toDelResID, 128, InputID);
	int intOfToDelResID = strtol(toDelResID, NULL, 10);
	if (!DelResident(intOfToDelResID)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "δ��ѯ���ñ���û�������������", "��ʾ", MB_OK);
	}
	LoadResidentInfoFile();
	forceToFlashButton = 1;
}

void ReWriteResFront() {
	SaveInResiModify();
	HWND hndtipsDS = GetHWnd();
	int isok = MessageBox(hndtipsDS, "ȷ������Դ�ļ���", "��ʾ", MB_OKCANCEL);
	if (isok == IDOK) {
		
	}
	else if (isok == IDCANCEL) {
		return;
	}
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