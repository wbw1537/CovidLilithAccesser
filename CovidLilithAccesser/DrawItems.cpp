#include"DrawItems.h"


void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar)
{
	if (position.mouceActiv == position.mouceActivBefore) {
		return;
	}
	else {
		if (position.mouceActiv == 0)//out of the Button
		{
			clearrectangle(position.left, position.top, position.right, position.buttom);
			//set the color of the Button and size of it
			setfillcolor(RGB(outTheButton.red, outTheButton.blue, outTheButton.green));
			fillrectangle(position.left, position.top, position.right, position.buttom);
			setlinecolor(BLACK);
			setbkmode(TRANSPARENT);
			//set the text style
			LOGFONT f;
			gettextstyle(&f);
			_tcscpy_s(f.lfFaceName, _T("宋体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			f.lfHeight = sizeOfChar;
			f.lfWeight = 600;
			settextstyle(&f);
			settextcolor(BLACK);
			//draw the text in the Button
			RECT R = { position.left,position.top,position.right,position.buttom };
			drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		if (position.mouceActiv == 1)//in the Button
		{
			//clearrectangle(position.left, position.top, position.right, position.buttom);
			//set the color of the Button and size of it
			setfillcolor(RGB(inTheButton.red, inTheButton.blue, inTheButton.green));
			
			fillrectangle(position.left, position.top, position.right, position.buttom);
			/*
			setbkmode(TRANSPARENT);
			//set the text style
			LOGFONT f;
			gettextstyle(&f);
			_tcscpy_s(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			f.lfHeight = sizeOfChar;
			settextstyle(&f);
			settextcolor(BLACK);
			*/
			//draw the text in the Button
			RECT R = { position.left,position.top,position.right,position.buttom };
			drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			
		}
		if (position.mouceActiv == 2)
		{
			//clearrectangle(position.left, position.top, position.right, position.buttom);
			//set the color of the Button and size of it
			setfillcolor(RGB(clickTheButton.red, clickTheButton.blue, clickTheButton.green));
			
			fillrectangle(position.left, position.top, position.right, position.buttom);
			/*
			setbkmode(TRANSPARENT);
			//set the text style
			LOGFONT f;
			gettextstyle(&f);
			_tcscpy_s(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			f.lfHeight = sizeOfChar;
			settextstyle(&f);
			settextcolor(BLACK);
			*/
			//draw the text in the Button
			RECT R = { position.left,position.top,position.right,position.buttom };
			drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			
		}
	}
	//clearrectangle(position.left, position.top, position.right, position.buttom);

}
//use callback function
void CheckButton(MOUSEMSG m, rectProperties &Button, void (*doSth)(void), char* L_TEXT, int sizeOfChar) {
	Button.mouceActiv = 0;
	if (m.x > Button.left && m.y > Button.top && m.y < Button.buttom && m.x < Button.right) {
		Button.mouceActiv = 1;
		if (m.uMsg == WM_LBUTTONDOWN) {
			Button.mouceActiv = 2;
		}
		if (m.uMsg == WM_LBUTTONUP) {
			doSth();
		}
	}
	DrawButton(Button, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, L_TEXT, sizeOfChar);
	Button.mouceActivBefore = Button.mouceActiv;
}

void DrawTextsSingle(rectProperties position, char* fonts, char* L_TEXT, int sizeOfChar, int weightOfChar, int italic, rgbColor textColor) {
	LOGFONT f;
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T(fonts));
	f.lfQuality = ANTIALIASED_QUALITY;
	f.lfItalic = italic;
	f.lfWeight = weightOfChar;
	f.lfHeight = sizeOfChar;
	settextstyle(&f);
	settextcolor(RGB(textColor.red, textColor.green, textColor.blue));
	RECT R = { position.left,position.top,position.right,position.buttom };
	drawtext(L_TEXT, &R, DT_LEFT | DT_WORDBREAK);
}

void DrawLineButtonOfRes(int leftCoor, int topCoor, int rectWidth, int rectHeight, int sizeOfFont, resident* resinfo, MOUSEMSG m) {
	rectProperties rects[20];
	int tempLeftCoor = leftCoor, tempTopCoor = topCoor;
	for (int i = 0; i < 8; i++) {
		rects[i] = { tempLeftCoor,tempTopCoor,tempLeftCoor + rectWidth,tempTopCoor + rectHeight ,0,1 };
		tempLeftCoor += rectWidth;
		tempTopCoor += rectHeight;
	}
	//init the texts to print in the button
	char outPutText1[9][200];
	sprintf_s(outPutText1[0], 50,"%s",resinfo->name);
	sprintf_s(outPutText1[1], 50, "%s", resinfo->passwd);
	sprintf_s(outPutText1[2], 50, "%s", resinfo->fromProvince);
	sprintf_s(outPutText1[3], 50, "%ld", resinfo->ID);
	sprintf_s(outPutText1[4], 50, "%s", resinfo->belong);
	sprintf_s(outPutText1[5], 50, "%u", resinfo->building);
	sprintf_s(outPutText1[6], 50, "%s", resinfo->district);
	sprintf_s(outPutText1[7], 50, "%d", resinfo->ifRisky);

	for (int i = 0; i < 8; i++) {
		rects[i].mouceActiv = 0;
		if (m.x > rects[i].left && m.y > rects[i].top && m.y < rects[i].buttom && m.x < rects[i].right) {
			rects[i].mouceActiv = 1;
			if (m.uMsg == WM_LBUTTONDOWN) {
				rects[i].mouceActiv = 2;
			}
			if (m.uMsg == WM_LBUTTONUP) {
				switch (i) {
				case 0: {//name
					char* changeName = {0};
					TCHAR InputName[] = _T("请输入要修改的姓名");
					InputBox(changeName, 20, InputName);
					wchar_t* returnName;
					int iSize1;
					iSize1 = MultiByteToWideChar(CP_ACP, 0, changeName, -1, NULL, 0);
					returnName = (wchar_t*)malloc(iSize1 * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, changeName, -1, returnName, iSize1);
					wcscpy_s(resinfo->name, returnName);
				}
				case 1: {//passwd
					char* changePasswd = { 0 };
					TCHAR InputPasswd[] = _T("请输入要修改的用户密码");
					InputBox(changePasswd, 20, InputPasswd);
					strcpy_s(resinfo->passwd, changePasswd);
				}
				case 2: {//from Province
					char* changeProv = { 0 };
					TCHAR InputProv[] = _T("请输入要修改的省份");
					InputBox(changeProv, 20, InputProv);
					wchar_t* returnProv;
					int iSize2;
					iSize2 = MultiByteToWideChar(CP_ACP, 0, changeProv, -1, NULL, 0);
					returnProv = (wchar_t*)malloc(iSize2 * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, changeProv, -1, returnProv, iSize2);
					wcscpy_s(resinfo->fromProvince, returnProv);
				}
				case 3: {//ID
					char* changeID = { 0 };
					TCHAR InputID[] = _T("请输入要修改的ID");
					InputBox(changeID, 20, InputID);
					int returnID;
					returnID = strtol(changeID, NULL, 10);
					resinfo->ID = returnID;
				}
				case 4: {//belong to any volunteer
					char* changeBelongName = { 0 };
					TCHAR InputBelongName[] = _T("请输入要修改的管理员姓名");
					InputBox(changeBelongName, 20, InputBelongName);
					wchar_t* returnBelongName;
					int iSize3;
					iSize3 = MultiByteToWideChar(CP_ACP, 0, changeBelongName, -1, NULL, 0);
					returnBelongName = (wchar_t*)malloc(iSize3 * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, changeBelongName, -1, returnBelongName, iSize3);
					wcscpy_s(resinfo->belong, returnBelongName);
				}
				case 5: {//building
					char* changeBuilding = { 0 };
					TCHAR InputBuilding[] = _T("请输入要修改的楼栋");
					InputBox(changeBuilding, 20, InputBuilding);
					int returnBuilding;
					returnBuilding = strtol(changeBuilding, NULL, 10);
					resinfo->building = returnBuilding;
				}
				case 6: {//district
					char* changeDistrict = { 0 };
					TCHAR InputDistrict[] = _T("请输入要修改的小区名称");
					InputBox(changeDistrict, 20, InputDistrict);
					wchar_t* returnDistrict;
					int iSize4;
					iSize4 = MultiByteToWideChar(CP_ACP, 0, changeDistrict, -1, NULL, 0);
					returnDistrict = (wchar_t*)malloc(iSize4 * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, changeDistrict, -1, returnDistrict, iSize4);
					wcscpy_s(resinfo->belong, returnDistrict);
				}
				case 7: {//ifrisky
					char* changeIfRisky = { 0 };
					TCHAR InputIfRisky[] = _T("请输入要修改的风险等级，请输入1或0");
					InputBox(changeIfRisky, 20, InputIfRisky);
					int returnIfRisky;
					returnIfRisky = strtol(changeIfRisky, NULL, 10);
					resinfo->ifRisky = returnIfRisky;
				}
				}
			}
			DrawButton(rects[i], colorOutOfTheButton, colorInTheButton, colorClickingTheButton, outPutText1[i], sizeOfFont);
			rects[i].mouceActivBefore = rects[i].mouceActiv;
		}

	}

}
	//void DrawResiProfiles();
	//函数声明
	void drawAlpha(IMAGE * picture, int  picture_x, int picture_y); //x为要载入图片的X坐标，y为Y坐标

	// 载入PNG图并去透明部分
	void drawAlpha(IMAGE * picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
	{

		// 变量初始化
		DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
		DWORD* draw = GetImageBuffer();
		DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
		int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
		int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
		int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
		int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
		int dstX = 0;    //在显存里像素的角标

		// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
		for (int iy = 0; iy < picture_height; iy++)
		{
			for (int ix = 0; ix < picture_width; ix++)
			{
				int srcX = ix + iy * picture_width; //在显存里像素的角标
				int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
				int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
				int sg = ((src[srcX] & 0xff00) >> 8);   //G
				int sb = src[srcX] & 0xff;              //B
				if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
				{
					dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
					int dr = ((dst[dstX] & 0xff0000) >> 16);
					int dg = ((dst[dstX] & 0xff00) >> 8);
					int db = dst[dstX] & 0xff;
					draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
						| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
						| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
				}
			}
		}
	}