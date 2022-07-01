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
		_tcscpy_s(f.lfFaceName, _T("黑体"));
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
		_tcscpy_s(f.lfFaceName, _T("黑体"));
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
		_tcscpy_s(f.lfFaceName, _T("黑体"));
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


//函数声明
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y); //x为要载入图片的X坐标，y为Y坐标

// 载入PNG图并去透明部分
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
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