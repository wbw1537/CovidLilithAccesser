#include"CovidLilithAccesser.h"
#include"DrawBotton.h"

void DrawBotton(int left, int top, int right, int bottom, int rgb_R_before, int rgb_G_before, int rgb_B_before,
	int rgb_R_init, int rgb_G_init, int rgb_B_init, int rgb_R_after, int rgb_G_after, int rgb_B_after,
	char* L_TEXT_before, char* L_TEXT_init, char* L_TEXT_after, int moucePosition)
{

	if (moucePosition == 0)
	{

		clearrectangle(left, top, right, bottom);
		//边框设置
		setlinecolor(BLACK);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
		
		
		solidrectangle(left, top, right, bottom);
		setfillcolor(RGB(rgb_R_before, rgb_G_before, rgb_B_before));
		settextcolor(BLACK);
		RECT r = {left,top,right,bottom };			//获取按钮的矩形区域
		//drawtext(L_TEXT_before, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//设置文字的输出格式：居中，自动换行，使用系统字体，使用系统字体自动计算，并且输出文字
		drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//垂直居中，单行显示
	}
	if (moucePosition == 1)
	{

		clearrectangle(left, top, right, bottom);
		//边框设置
		setlinecolor(BROWN);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
		//渐变颜色设置
		int a = 10;				//颜色渐变区域
		int i = 0;				//局部变量i,用于循环变量
		double c = 255 / a;		//设置变化率
		//绘制渐变颜色变化边框
		for (i = 0; i < a; i++)
		{

			setlinecolor(RGB(c * i, c * i, c * i));
			line(left - i, top - i, left - i, bottom + i);
			line(left - i, top - i, right + i, top - i);
			line(right + i, top - i, right + i, bottom - i);
			line(left - i, bottom + i, right + i, bottom + i);
		}
		//设置矩形区域填充颜色
		solidrectangle(left, top, right, bottom);
		setfillcolor(RGB(rgb_R_init, rgb_G_init, rgb_B_init));
		//setfillcolor(RGB(128, 128, 135));			//灰色
		settextcolor(BLACK);
		RECT r = {left,top,right,bottom };			//获取按钮的矩形区域
		drawtext(L_TEXT_init, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//设置文字的输出格式：居中，自动换行，使用系统字体，使用系统字体自动计算，并且输出文字
		//drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//垂直居中，单行显示
	}
	if (moucePosition == 2)
	{

		clearrectangle(left, top, right, bottom);
		//边框设置
		setlinecolor(BLACK);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
	}
	//渐变颜色设置
	int a = 10;				//颜色渐变区域
	int i = 0;				//局部变量i,用于循环变量
	double c = 255 / a;		//设置变化率
	//绘制渐变颜色变化边框
	for (i = 0; i < a; i++)
	{

		setlinecolor(RGB(c * i, c * i, c * i));
		line(left - i, top - i, left - i, bottom + i);
		line(left - i, top - i, right + i, top - i);
		line(right + i, top - i, right + i, bottom - i);
		line(left - i, bottom + i, right + i, bottom + i);
	}
	solidrectangle(left, top, right, bottom);
	setfillcolor(RGB(rgb_R_after, rgb_G_after, rgb_B_after));
	settextcolor(BLACK);
	RECT r = {left,top,right,bottom };			//获取按钮的矩形区域
	drawtext(L_TEXT_after, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//设置文字的输出格式：居中，自动换行，使用系统字体，使用系统字体自动计算，并且输出文字
	//drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//垂直居中，单行显示
}

