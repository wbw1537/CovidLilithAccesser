#include"CovidLilithAccesser.h"
#include"DrawTheButton.h"

void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar, int moucePosition)
{
	if (moucePosition == 0)//out of the Button
	{
		//set the color of the Button and size of it
		setfillcolor(RGB(outTheButton.red, outTheButton.blue, outTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("ËÎÌו"));
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
		//set the color of the Button and size of it
		setfillcolor(RGB(inTheButton.red, inTheButton.blue, inTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("ËÎÌו"));
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
		//set the color of the Button and size of it
		setfillcolor(RGB(clickTheButton.red, clickTheButton.blue, clickTheButton.green));
		fillrectangle(position.left, position.top, position.right, position.buttom);
		setbkmode(TRANSPARENT);
		//set the text style
		LOGFONT f;
		gettextstyle(&f);
		_tcscpy_s(f.lfFaceName, _T("ËÎÌו"));
		f.lfQuality = ANTIALIASED_QUALITY;
		f.lfHeight = sizeOfChar;
		settextstyle(&f);
		settextcolor(BLACK);
		//draw the text in the Button
		RECT R = { position.left,position.top,position.right,position.buttom };
		drawtext(L_TEXT, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
