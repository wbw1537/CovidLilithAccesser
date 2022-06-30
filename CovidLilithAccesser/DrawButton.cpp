#include"CovidLilithAccesser.h"
#include"DrawBotton.h"

void DrawBotton(int left, int top, int right, int bottom, int rgb_R_before, int rgb_G_before, int rgb_B_before,
	int rgb_R_init, int rgb_G_init, int rgb_B_init, int rgb_R_after, int rgb_G_after, int rgb_B_after,
	char* L_TEXT_before, char* L_TEXT_init, char* L_TEXT_after, int moucePosition)
{

	if (moucePosition == 0)
	{

		clearrectangle(left, top, right, bottom);
		//�߿�����
		setlinecolor(BLACK);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
		
		
		solidrectangle(left, top, right, bottom);
		setfillcolor(RGB(rgb_R_before, rgb_G_before, rgb_B_before));
		settextcolor(BLACK);
		RECT r = {left,top,right,bottom };			//��ȡ��ť�ľ�������
		//drawtext(L_TEXT_before, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//�������ֵ������ʽ�����У��Զ����У�ʹ��ϵͳ���壬ʹ��ϵͳ�����Զ����㣬�����������
		drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//��ֱ���У�������ʾ
	}
	if (moucePosition == 1)
	{

		clearrectangle(left, top, right, bottom);
		//�߿�����
		setlinecolor(BROWN);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
		//������ɫ����
		int a = 10;				//��ɫ��������
		int i = 0;				//�ֲ�����i,����ѭ������
		double c = 255 / a;		//���ñ仯��
		//���ƽ�����ɫ�仯�߿�
		for (i = 0; i < a; i++)
		{

			setlinecolor(RGB(c * i, c * i, c * i));
			line(left - i, top - i, left - i, bottom + i);
			line(left - i, top - i, right + i, top - i);
			line(right + i, top - i, right + i, bottom - i);
			line(left - i, bottom + i, right + i, bottom + i);
		}
		//���þ������������ɫ
		solidrectangle(left, top, right, bottom);
		setfillcolor(RGB(rgb_R_init, rgb_G_init, rgb_B_init));
		//setfillcolor(RGB(128, 128, 135));			//��ɫ
		settextcolor(BLACK);
		RECT r = {left,top,right,bottom };			//��ȡ��ť�ľ�������
		drawtext(L_TEXT_init, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//�������ֵ������ʽ�����У��Զ����У�ʹ��ϵͳ���壬ʹ��ϵͳ�����Զ����㣬�����������
		//drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//��ֱ���У�������ʾ
	}
	if (moucePosition == 2)
	{

		clearrectangle(left, top, right, bottom);
		//�߿�����
		setlinecolor(BLACK);
		line(left, top, left, bottom);
		line(left, top, right, top);
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
	}
	//������ɫ����
	int a = 10;				//��ɫ��������
	int i = 0;				//�ֲ�����i,����ѭ������
	double c = 255 / a;		//���ñ仯��
	//���ƽ�����ɫ�仯�߿�
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
	RECT r = {left,top,right,bottom };			//��ȡ��ť�ľ�������
	drawtext(L_TEXT_after, &r, DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_INTERNAL);//�������ֵ������ʽ�����У��Զ����У�ʹ��ϵͳ���壬ʹ��ϵͳ�����Զ����㣬�����������
	//drawtext(L_TEXT_before, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);			//��ֱ���У�������ʾ
}

