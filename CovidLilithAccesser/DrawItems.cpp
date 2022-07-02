#include"DrawItems.h"


void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar)
{
	if (position.mouceActiv == position.mouceActivBefore && lastIndexToDrawPage == indexToDrawPage && !forceToFlashButton) {
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
			_tcscpy_s(f.lfFaceName, _T("����"));
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
			_tcscpy_s(f.lfFaceName, _T("����"));
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
			_tcscpy_s(f.lfFaceName, _T("����"));
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


void DrawLineButtonOfRes(rectProperties rects[], int sizeOfFont, resident* resinfo, MOUSEMSG m) {
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
					char changeName[64];
					TCHAR InputName[] = _T("������Ҫ�޸ĵ�����");
					InputBox(changeName, 20, InputName);
					strcpy_s(resinfo->name, changeName);
					break;
				}
				case 1: {//passwd
					char changePasswd[64];
					TCHAR InputPasswd[] = _T("������Ҫ�޸ĵ��û�����");
					InputBox(changePasswd, 20, InputPasswd);
					strcpy_s(resinfo->passwd, changePasswd);
					break;
				}
				case 2: {//from Province
					char changeProv[64];
					TCHAR InputProv[] = _T("������Ҫ�޸ĵ�ʡ��");
					InputBox(changeProv, 20, InputProv);
					strcpy_s(resinfo->fromProvince, changeProv);
					break;
				}
				case 3: {//ID
					char changeID[64];
					TCHAR InputID[] = _T("������Ҫ�޸ĵ�ID");
					InputBox(changeID, 20, InputID);
					long returnID;
					returnID = strtol(changeID, NULL, 10);
					for (int i = 0; i < numOfRes; i++) {
						if (residentInfo[i].ID = returnID) {
							HWND SignError = GetHWnd();
							int isok = MessageBox(SignError, "�ñ���Ѿ����ڣ�����������", "��ʾ", MB_OK);
							break;
						}
						resinfo->ID = returnID;
					}
					break;
				}
				case 4: {//belong to any volunteer
					char changeBelongName[64];
					TCHAR InputBelongName[] = _T("������Ҫ�޸ĵĹ���Ա����");
					InputBox(changeBelongName, 20, InputBelongName);
					strcpy_s(resinfo->belong, changeBelongName);
					break;
				}
				case 5: {//building
					char changeBuilding[64];
					TCHAR InputBuilding[] = _T("������Ҫ�޸ĵ�¥��");
					InputBox(changeBuilding, 20, InputBuilding);
					int returnBuilding;
					returnBuilding = strtol(changeBuilding,NULL, 10);
					resinfo->building = returnBuilding;
					break;
				}
				case 6: {//district
					char changeDistrict[64];
					TCHAR InputDistrict[] = _T("������Ҫ�޸ĵ�С������");
					InputBox(changeDistrict, 20, InputDistrict);
					strcpy_s(resinfo->district, changeDistrict);
					break;
				}
				case 7: {//ifrisky
					char changeIfRisky[64];
					TCHAR InputIfRisky[] = _T("������Ҫ�޸ĵķ��յȼ���������1��0");
					InputBox(changeIfRisky, 20, InputIfRisky);
					int returnIfRisky;
					returnIfRisky = strtol(changeIfRisky, NULL, 10);
					resinfo->ifRisky = returnIfRisky;
					break;
				}
				}
			}
			
		}
		DrawButton(rects[i], colorOutOfTheButton, colorInTheButton, colorClickingTheButton, outPutText1[i], sizeOfFont);
		rects[i].mouceActivBefore = rects[i].mouceActiv;

	}

}
	//void DrawResiProfiles();
	//��������
	void drawAlpha(IMAGE * picture, int  picture_x, int picture_y); //xΪҪ����ͼƬ��X���꣬yΪY����

	// ����PNGͼ��ȥ͸������
	void drawAlpha(IMAGE * picture, int  picture_x, int picture_y) //xΪ����ͼƬ��X���꣬yΪY����
	{

		// ������ʼ��
		DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
		DWORD* draw = GetImageBuffer();
		DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
		int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
		int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
		int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
		int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
		int dstX = 0;    //���Դ������صĽǱ�

		// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
		for (int iy = 0; iy < picture_height; iy++)
		{
			for (int ix = 0; ix < picture_width; ix++)
			{
				int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
				int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
				int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
				int sg = ((src[srcX] & 0xff00) >> 8);   //G
				int sb = src[srcX] & 0xff;              //B
				if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
				{
					dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
					int dr = ((dst[dstX] & 0xff0000) >> 16);
					int dg = ((dst[dstX] & 0xff00) >> 8);
					int db = dst[dstX] & 0xff;
					draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
						| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
						| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
				}
			}
		}
	}