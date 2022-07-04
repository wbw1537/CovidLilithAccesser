#include"InfoPage.h"
#pragma warning(disable : 4996)

void InfoPage(int type,int nowType){

	MOUSEMSG m4;
	InfoPageOpen = 1;

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

	char adminText1[50] = { "用户信息管理系统:" };
	char adminText2[50];

	if (type == AdminToVol && nowType == Administrator) {
		char AdminToVolText[50] = {"管理员发件箱："};
		strcpy(adminText2, AdminToVolText);
	}
	if (type == AdminToVol && nowType == Volunteer) {
		char AdminToVolText[50] = { "工作人员收件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == VolToAdmin && nowType == Administrator) {
		char AdminToVolText[50] = { "管理员收件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == VolToAdmin && nowType == Volunteer) {
		char AdminToVolText[50] = { "工作人员发件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == ResiToVol && nowType == Volunteer) {
		char AdminToVolText[50] = { "工作人员收件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == ResiToVol && nowType == Residente) {
		char AdminToVolText[50] = { "用户发件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == VolToResi && nowType == Residente) {
		char AdminToVolText[50] = { "用户收件箱：" };
		strcpy(adminText2, AdminToVolText);
	}
	if (type == VolToResi && nowType == Volunteer) {
		char AdminToVolText[50] = { "工作人员发件箱：" };
		strcpy(adminText2, AdminToVolText);
	}

	DrawTextsSingle(text1, songTi, adminText1, 30, 600, 0, blueOfText);
	DrawTextsSingle(text2, songTi, adminText2, 20, 500, 0, blackOfText);

	char exitButtonText[50] = { "退出" };
	char nextPageButtonText[50] = { "下移" };
	char lastPageButtonText[50] = { "上移" };
	char addUserInfoText[50] = { "发布信息" };
	char delUserInfoText[50] = { "删除信息" };
	char reWriteUserInfoText[50] = { "切换发出/收到" };


	rectProperties exitButtonCorr, nextPageButtonCorr, lastPageButtonCorr;
	rectProperties addUserInfoCorr, delUserInfoCorr, reWriteUserInfoCorr;
	int downLeftCorr = 100, downTopCorr = 470, downButtonWidth = 120, downButtonHeight = 40;
	//int tempDownLeftCorr = downLeftCorr;
	rectProperties rectSolve = { 528,122,637,159,0,1 };

	addUserInfoCorr = { downLeftCorr,downTopCorr,downLeftCorr + 1 * downButtonWidth + 0 * 10,downTopCorr + downButtonHeight,0,1 };
	delUserInfoCorr = { downLeftCorr + 1 * downButtonWidth + 1 * 10,downTopCorr,downLeftCorr + 2 * downButtonWidth + 1 * 10,downTopCorr + downButtonHeight,0,1 };
	reWriteUserInfoCorr = { downLeftCorr + 2 * downButtonWidth + 2 * 10,downTopCorr,downLeftCorr + 3 * downButtonWidth + 2 * 10,downTopCorr + downButtonHeight,0,1 };
	lastPageButtonCorr = { downLeftCorr + 3 * downButtonWidth + 3 * 10,downTopCorr,downLeftCorr + 4 * downButtonWidth + 3 * 10,downTopCorr + downButtonHeight,0,1 };
	nextPageButtonCorr = { downLeftCorr + 4 * downButtonWidth + 4 * 10,downTopCorr,downLeftCorr + 5 * downButtonWidth + 4 * 10,downTopCorr + downButtonHeight,0,1 };
	exitButtonCorr = { downLeftCorr + 5 * downButtonWidth + 5 * 10,downTopCorr,downLeftCorr + 6 * downButtonWidth + 5 * 10,downTopCorr + downButtonHeight,0,1 };

	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);
	DrawButton(rectSolve, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);

	
	TextExchange *textExchage = {0};
	if (type == AdminToVol) {
		textExchage = AdminToVOlMessageList;
	}
	if (type == VolToAdmin) {
		textExchage = VolToAdminMessageList;
	}
	if (type == ResiToVol) {
		textExchage = ResiToVolMessageList;
	}
	if (type == VolToResi) {
		textExchage = VolToResiMessageList;
	}
	
	indexToDrawPage = 0;

	do {

		m4 = GetMouseMsg();
		
		CheckButton(m4, exitButtonCorr, ExitButtonForAdminInfoPage, exitButtonText, 20);
		
		DrawTextModule(m4, textExchage[indexToDrawPage]);

		forceToFlashButton = 0;

	} while (InfoPageOpen);
	free(textExchage);
}

void ExitButtonForAdminInfoPage() {
	InfoPageOpen = 0;
	AdminPage();
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
	
	char adminText1[50] = { "用户信息管理系统:" };
	char adminText2[50] = {"点击各个单元格可修改单元格内容"};

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


	char exitButtonText[50] = { "退出" };
	char nextPageButtonText[50] = { "下移" };
	char lastPageButtonText[50] = { "上移" };
	char addUserInfoText[50] = { "添加用户" };
	char delUserInfoText[50] = { "删除用户" };
	char reWriteUserInfoText[50] = { "覆写文件" };

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
		CheckButton(m3, nextPageButtonCorr, NextPageButtonRes, nextPageButtonText, 20);
		CheckButton(m3, lastPageButtonCorr, LastPageButtonRes, lastPageButtonText, 20);
		CheckButton(m3, addUserInfoCorr, AddResidentFront, addUserInfoText, 20);
		CheckButton(m3, delUserInfoCorr, DelResidentFront, delUserInfoText, 20);
		CheckButton(m3, reWriteUserInfoCorr, ReWriteResFront, reWriteUserInfoText, 20);
	
	} while (ResiManagePageOpen);
}



void ReciManageMenuForVol() {
	MOUSEMSG m3;
	ReciManageMenuForVolOpen = 1;
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

	char adminText1[50] = { "用户信息管理系统:" };
	char adminText2[50] = { "点击各个单元格可修改单元格内容" };

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


	char exitButtonText[50] = { "退出" };
	char nextPageButtonText[50] = { "下移" };
	char lastPageButtonText[50] = { "上移" };
	char addUserInfoText[50] = { "添加用户" };
	char delUserInfoText[50] = { "删除用户" };
	char reWriteUserInfoText[50] = { "覆写文件" };

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
		rects1[i] = { tempLeftCoor,tempTopCoor + 0 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 1 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects2[i] = { tempLeftCoor,tempTopCoor + 1 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 2 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects3[i] = { tempLeftCoor,tempTopCoor + 2 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 3 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects4[i] = { tempLeftCoor,tempTopCoor + 3 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 4 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects5[i] = { tempLeftCoor,tempTopCoor + 4 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 5 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects6[i] = { tempLeftCoor,tempTopCoor + 5 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 6 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects7[i] = { tempLeftCoor,tempTopCoor + 6 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 7 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects8[i] = { tempLeftCoor,tempTopCoor + 7 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 8 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects9[i] = { tempLeftCoor,tempTopCoor + 8 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 9 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}

	char outputText1[10][50] = { "姓名"," ","来源地","编号","所属","楼栋","辖区","风险等级" };

	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);
	DrawButton(lastPageButtonCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, lastPageButtonText, 20);
	DrawButton(nextPageButtonCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, nextPageButtonText, 20);
	DrawButton(addUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, addUserInfoText, 20);
	DrawButton(delUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, delUserInfoText, 20);
	DrawButton(reWriteUserInfoCorr, colorInTheButton, colorInTheButton, colorClickingTheButton, reWriteUserInfoText, 20);




	//output the title of the sheet
	for (int i = 0; i < 8; i++) {
		if (i == 1) continue;
		DrawButton(rects0[i], colorOfBackGround, colorOfBackGround, colorOfBackGround, outputText1[i], 20);
	}

	indexToDrawPage = 0;

	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfResForVol(rects1, 15, &residentInfo[indexToDrawPage + 0], m3);
		DrawLineButtonOfResForVol(rects2, 15, &residentInfo[indexToDrawPage + 1], m3);
		DrawLineButtonOfResForVol(rects3, 15, &residentInfo[indexToDrawPage + 2], m3);
		DrawLineButtonOfResForVol(rects4, 15, &residentInfo[indexToDrawPage + 3], m3);
		DrawLineButtonOfResForVol(rects5, 15, &residentInfo[indexToDrawPage + 4], m3);
		DrawLineButtonOfResForVol(rects6, 15, &residentInfo[indexToDrawPage + 5], m3);
		DrawLineButtonOfResForVol(rects7, 15, &residentInfo[indexToDrawPage + 6], m3);
		DrawLineButtonOfResForVol(rects8, 15, &residentInfo[indexToDrawPage + 7], m3);
		DrawLineButtonOfResForVol(rects9, 15, &residentInfo[indexToDrawPage + 8], m3);

		lastIndexToDrawPage = indexToDrawPage;
		forceToFlashButton = 0;

		CheckButton(m3, exitButtonCorr, EndResiManageMenuForVol, exitButtonText, 20);
		CheckButton(m3, nextPageButtonCorr, NextPageButtonRes, nextPageButtonText, 20);
		CheckButton(m3, lastPageButtonCorr, LastPageButtonRes, lastPageButtonText, 20);
		CheckButton(m3, addUserInfoCorr, AddResidentFront, addUserInfoText, 20);
		CheckButton(m3, delUserInfoCorr, DelResidentFront, delUserInfoText, 20);
		CheckButton(m3, reWriteUserInfoCorr, ReWriteResFront, reWriteUserInfoText, 20);

	} while (ReciManageMenuForVolOpen);
}


void ReciManageMenuForResi() {
	MOUSEMSG m3;
	ResiManageMenuForResiOpen = 1;
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

	char adminText1[50] = { "用户信息管理系统:" };
	char adminText2[50] = { "点击各个单元格可修改单元格内容" };
	char reWriteUserInfoText[50] = { "覆写文件" };

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


	char exitButtonText[50] = { "退出" };
	//print sheet
	int leftCoor = 22, topCoor = 250, rectWidth = 115, rectHeight = 30;

	rectProperties rects0[20];
	rectProperties rects1[20];

	int tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects0[i] = { tempLeftCoor,tempTopCoor - 1 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 0 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects1[i] = { tempLeftCoor,tempTopCoor + 0 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 1 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}

	char outputText1[10][50] = { "姓名","用户密码","来源地","编号","所属","楼栋","辖区","风险等级" };

	DrawButton(exitButtonCorr, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, exitButtonText, 20);

	//output the title of the sheet
	for (int i = 0; i < 8; i++) {
		DrawButton(rects0[i], colorOfBackGround, colorOfBackGround, colorOfBackGround, outputText1[i], 20);
	}

	indexToDrawPage = 0;

	do {
		m3 = GetMouseMsg();
		DrawLineButtonOfRes(rects1, 15, &nowLoginResi, m3);
		
		lastIndexToDrawPage = indexToDrawPage;
		forceToFlashButton = 0;

		CheckButton(m3, exitButtonCorr, EndResiManageMenuForResi, exitButtonText, 20);
		CheckButton(m3, reWriteUserInfoCorr, ReWriteResFront, reWriteUserInfoText, 20);

	} while (ResiManageMenuForResiOpen);
}

void EndResiManageMenuForResi() {
	ResiManageMenuForResiOpen = 0;
	ResiPage();
}

void NextPageButtonRes() {
	if (indexToDrawPage < numOfRes) {
		indexToDrawPage++;
	}
	else {
		return;
	}
}
void LastPageButtonRes() {
	if (indexToDrawPage > 0) {
		indexToDrawPage--;
	}
	else return;
}


void AddResidentFront() {
	resident residentInfo;
	char resName[128], resPasswd[128], resFromProvince[128], resID[128], 
		resBelong[128], resBuilding[128], resDistrict[128], resIfRisky[128];
	TCHAR InputName[] = _T("请输入姓名");
	InputBox(resName, 128, InputName);
	TCHAR InputPAsswd[] = _T("请输入密码");
	InputBox(resPasswd, 128, InputPAsswd);
	TCHAR InputProv[] = _T("请输入来源地");
	InputBox(resFromProvince, 128, InputProv);
	TCHAR InputID[] = _T("请输入编号");
	InputBox(resID, 128, InputID);
	TCHAR InputBelong[] = _T("请输入所属工作人员");
	InputBox(resBelong, 128, InputBelong);
	TCHAR InputBuilding[] = _T("请输入居住楼栋");
	InputBox(resBuilding, 128, InputBuilding);
	TCHAR InputDistrict[] = _T("请输入辖区");
	InputBox(resDistrict, 128, InputDistrict);
	TCHAR InputIfRisky[] = _T("请输入风险等级");
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
		int isok = MessageBox(SignError, "该编号已经存在，请重新添加", "提示", MB_OK);
	}
	LoadResidentInfoFile();
	forceToFlashButton = 1;
}

void DelResidentFront(){
	char toDelResID[64];
	TCHAR InputID[] = _T("请输入要删除的用户编号");
	InputBox(toDelResID, 128, InputID);
	int intOfToDelResID = strtol(toDelResID, NULL, 10);
	if (!DelResident(intOfToDelResID)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "未查询到该编号用户，请重新输入", "提示", MB_OK);
	}
	LoadResidentInfoFile();
	forceToFlashButton = 1;
}

void ReWriteResFront() {
	HWND hndtipsDS = GetHWnd();
	int isok = MessageBox(hndtipsDS, "确定覆盖源文件？", "提示", MB_OKCANCEL);
	if (isok == IDOK) {
		SaveInResiModify();
		LoadResidentInfoFile();
	}
	else if (isok == IDCANCEL) {
		return;
	}
}


void EndResiManageMenu(){
	ResiManagePageOpen = 0;
	AdminPage();
}

void EndResiManageMenuForVol() {
	ReciManageMenuForVolOpen = 0;
	VolPage();
}

void VolManageMenu() {
	MOUSEMSG m3;
	VolManagePageOpen = 1;
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

	char adminText1[50] = { "社区工作者信息管理系统:" };
	char adminText2[50] = { "点击各个单元格可修改单元格内容" };

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


	char exitButtonText[50] = { "退出" };
	char nextPageButtonText[50] = { "下移" };
	char lastPageButtonText[50] = { "上移" };
	char addUserInfoText[50] = { "添加工作者" };
	char delUserInfoText[50] = { "删除工作者" };
	char reWriteUserInfoText[50] = { "覆写文件" };

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
		rects1[i] = { tempLeftCoor,tempTopCoor + 0 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 1 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects2[i] = { tempLeftCoor,tempTopCoor + 1 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 2 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects3[i] = { tempLeftCoor,tempTopCoor + 2 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 3 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects4[i] = { tempLeftCoor,tempTopCoor + 3 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 4 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects5[i] = { tempLeftCoor,tempTopCoor + 4 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 5 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects6[i] = { tempLeftCoor,tempTopCoor + 5 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 6 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects7[i] = { tempLeftCoor,tempTopCoor + 6 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 7 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects8[i] = { tempLeftCoor,tempTopCoor + 7 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 8 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}
	tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects9[i] = { tempLeftCoor,tempTopCoor + 8 * rectHeight,tempLeftCoor + rectWidth,tempTopCoor + 9 * rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
	}

	char outputText1[10][50] = { "姓名","密码","编号","年龄","性别","部门","手机号码","职务" };

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
		DrawLineButtonOfVol(rects1, 15, &volunteerInfo[indexToDrawPage + 0], m3);
		DrawLineButtonOfVol(rects2, 15, &volunteerInfo[indexToDrawPage + 1], m3);
		DrawLineButtonOfVol(rects3, 15, &volunteerInfo[indexToDrawPage + 2], m3);
		DrawLineButtonOfVol(rects4, 15, &volunteerInfo[indexToDrawPage + 3], m3);
		DrawLineButtonOfVol(rects5, 15, &volunteerInfo[indexToDrawPage + 4], m3);
		DrawLineButtonOfVol(rects6, 15, &volunteerInfo[indexToDrawPage + 5], m3);
		DrawLineButtonOfVol(rects7, 15, &volunteerInfo[indexToDrawPage + 6], m3);
		DrawLineButtonOfVol(rects8, 15, &volunteerInfo[indexToDrawPage + 7], m3);
		DrawLineButtonOfVol(rects9, 15, &volunteerInfo[indexToDrawPage + 8], m3);

		lastIndexToDrawPage = indexToDrawPage;
		forceToFlashButton = 0;

		CheckButton(m3, exitButtonCorr, EndVolManageMenu, exitButtonText, 20);
		CheckButton(m3, nextPageButtonCorr, NextPageButtonVol, nextPageButtonText, 20);
		CheckButton(m3, lastPageButtonCorr, LastPageButtonVol, lastPageButtonText, 20);
		CheckButton(m3, addUserInfoCorr, AddVolFront, addUserInfoText, 20);
		CheckButton(m3, delUserInfoCorr, DelVolFront, delUserInfoText, 20);
		CheckButton(m3, reWriteUserInfoCorr, ReWriteVolFront, reWriteUserInfoText, 20);

	} while (VolManagePageOpen);
}

void NextPageButtonVol() {
	if (indexToDrawPage < numOfVol) {
		indexToDrawPage++;
	}
	else {
		return;
	}
}
void LastPageButtonVol() {
	if (indexToDrawPage > 0) {
		indexToDrawPage--;
	}
	else return;
}




void AddVolFront() {
	volunteer volinfo;

	char changeName[64] = {0};
	TCHAR InputName[] = _T("请输入姓名");
	InputBox(changeName, 20, InputName);

	char changePasswd[64] = { 0 };
	TCHAR InputPasswd[] = _T("请输入密码");
	InputBox(changePasswd, 20, InputPasswd);

	char changeID[64] = { 0 };
	TCHAR InputID[] = _T("请输入编号");
	InputBox(changeID, 20, InputID);

	char changeAge[64] = { 0 };
	TCHAR InputAge[] = _T("请输入年龄");
	InputBox(changeAge, 20, InputAge);

	char changeSex[64] = { 0 };
	TCHAR InputSex[] = _T("请输入性别");
	InputBox(changeSex, 20, InputSex);

	char changeDepartments[64] = { 0 };
	TCHAR InputDepartments[] = _T("请输入部门");
	InputBox(changeDepartments, 20, InputDepartments);

	char changePhone[64] = { 0 };
	TCHAR InputPhone[] = _T("请输入电话号码");
	InputBox(changePhone, 20, InputPhone);

	char changePosition[64] = { 0 };
	TCHAR InputPosition[] = _T("请输入职务");
	InputBox(changePosition, 20, InputPosition);
	char changeWechat[64] = { "0"};

	strcpy_s(volinfo.name, changeName);
	strcpy_s(volinfo.passwd, changePasswd);
	volinfo.ID = strtol(changeID, NULL, 10);
	volinfo.age = strtol(changeAge, NULL, 10);
	volinfo.sex = strtol(changeSex, NULL, 10);
	strcpy_s(volinfo.department, changeDepartments);
	strcpy_s(volinfo.phone, changePhone);
	strcpy_s(volinfo.position, changePosition);
	strcpy_s(volinfo.wechat, changeWechat);
	
	if (AddVolunteer(volinfo)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "该编号已经存在，请重新添加", "提示", MB_OK);
	}
	LoadVolInfoFile();
	forceToFlashButton = 1;
}

void DelVolFront() {
	char toDelVolID[64];
	TCHAR InputID[] = _T("请输入要删除的工作者编号");
	InputBox(toDelVolID, 128, InputID);
	int intOfToDelVolID = strtol(toDelVolID, NULL, 10);
	if (!DelVolunteer(intOfToDelVolID)) {
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "未查询到该编号工作者，请重新输入", "提示", MB_OK);
	}
	LoadVolInfoFile();
	forceToFlashButton = 1;
}

void ReWriteVolFront() {
	HWND hndtipsDS = GetHWnd();
	int isok = MessageBox(hndtipsDS, "确定覆盖源文件？", "提示", MB_OKCANCEL);
	if (isok == IDOK) {
		SaveInVolModify();
	}
	else if (isok == IDCANCEL) {
		return;
	}
}


void EndVolManageMenu() {
	VolManagePageOpen = 0;
	AdminPage();
}




bool WriteMessageFile(TextExchange toadd) {
	FILE* fp = { 0 };
	fp = fopen(".\\data\\message", "a");
	fprintf(fp, "%d ,%d ,%s ,%s ,%s\n", toadd.messageType, toadd.isSolve, toadd.title, toadd.message, toadd.reply);
	fclose(fp);
	return 0;
}

bool ReadMessageFile(TextExchange* MessageList, int type, int num) {
	MessageList = (TextExchange*)malloc(5 * sizeof(TextExchange));
	ZeroMemory(MessageList, 5 * sizeof(TextExchange));
	int size[5] = {5,5,5,5,5}, index[5] = {0};
	TextExchange tmp = { 0 };
	TextExchange* tmpArray;
	FILE* fp = fopen(".\\data\\message", "r");
	while (fscanf_s(fp, "%d ,%d ,%s ,%s ,%s",
		&tmp.messageType, &tmp.isSolve, tmp.title, 500, tmp.message, 500, tmp.reply, 500) == 5
		) {
		if (tmp.messageType == type) {
			MessageList[index[type]] = tmp;
		}
		if (index[type] == size[type] - 1) {
			tmpArray = MessageList;
			MessageList = (TextExchange*)malloc(2 * size[type] * sizeof(TextExchange));
			if (MessageList == NULL) return false;
			ZeroMemory(MessageList, 2 * size[type] * sizeof(TextExchange));
			for (int i = 0; i < size[type]; i++) {
				MessageList[i] = tmpArray[i];
			}
			size[type] *= 2;
		}
		if (tmp.messageType == type) {
			index[type]++;
		}
	}
	num = index[type];
	return true;
}
