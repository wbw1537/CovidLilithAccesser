#include"CovidLilithAccesser.h"
#include"DrawItems.h"

void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar, int moucePosition)
{
	if (moucePosition == 0)//out of the Button
	{
		//clearrectangle(position.left, position.top, position.right, position.buttom);
		//set the color of the Button and size of it
		setfillcolor(RGB(outTheButton.red, outTheButton.blue, outTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("����"));
		f.lfQuality = ANTIALIASED_QUALITY;
		f.lfHeight = sizeOfChar;
		settextstyle(&f);
		settextcolor(BLACK);
		//draw the text in the Button
		RECT R = { position.left,position.top,position.right,position.buttom };
		drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (moucePosition == 1)//in the Button
	{
		//clearrectangle(position.left, position.top, position.right, position.buttom);
		//set the color of the Button and size of it
		setfillcolor(RGB(inTheButton.red, inTheButton.blue, inTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("����"));
		f.lfQuality = ANTIALIASED_QUALITY;
		f.lfHeight = sizeOfChar;
		settextstyle(&f);
		settextcolor(BLACK);
		//draw the text in the Button
		RECT R = { position.left,position.top,position.right,position.buttom };
		drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (moucePosition == 2)
	{
		//clearrectangle(position.left, position.top, position.right, position.buttom);
		//set the color of the Button and size of it
		setfillcolor(RGB(clickTheButton.red, clickTheButton.blue, clickTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("����"));
		f.lfQuality = ANTIALIASED_QUALITY;
		f.lfHeight = sizeOfChar;
		settextstyle(&f);
		settextcolor(BLACK);
		//draw the text in the Button
		RECT R = { position.left,position.top,position.right,position.buttom };
		drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	//
	if (moucePosition == 3) {
		clearrectangle(position.left, position.top, position.right, position.buttom);
	}
}


//��������
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y); //xΪҪ����ͼƬ��X���꣬yΪY����

// ����PNGͼ��ȥ͸������
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //xΪ����ͼƬ��X���꣬yΪY����
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