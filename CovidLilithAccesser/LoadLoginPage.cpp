#include"CovidLilithAccesser.h"
#include"LoadLoginPage.h"

MOUSEMSG m1;


//load the login page
void LoadLoginPage() {
	
	//load background image and logo image, then print them
	IMAGE backGround, logo, title;
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&logo, "resources/covidProofWorkers.jpg", 350, 227);
	loadimage(&title, "resources/title.png");
	putimage(0, 0, &backGround);
	putimage(80, WINDOWHEIGHT / 2 - logo.getheight() / 2 - 30, &logo);
	drawAlpha(&title, 500, 80);
	
	/*
	//load the button png and print.
	IMAGE loginAsUser, loginAsAdmin, loginAsVolunteer;
	loadimage(&loginAsUser, "resources/loginAsUser.png", 140, 45);
	loadimage(&loginAsAdmin, "resources/loginAsAdmin.png", 140, 45);
	loadimage(&loginAsVolunteer, "resources/loginAsVlounteer.png", 140, 45);
	drawAlpha(&loginAsAdmin, 470, 400);
	drawAlpha(&loginAsVolunteer, 620, 400);
	drawAlpha(&loginAsUser, 770, 400);
	*/

	setfillcolor(RGB(228, 228, 228));
	fillrectangle(470, 400, 610, 445);
	fillrectangle(620, 400, 760, 445);
	fillrectangle(770, 400, 910, 445);
	setbkmode(TRANSPARENT);

	LOGFONT f;
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("Microsoft YaHei"));
	f.lfQuality = ANTIALIASED_QUALITY;
	f.lfHeight = 30;
	settextstyle(&f);
	char FirstSelect1[20] = { "����Ա��¼" };
	char FirstSelect2[20] = { "���������ߵ�¼" };
	char FirstSelect3[20] = { "�û�ע��/��¼" };
	RECT R[3] = { {470, 400, 610, 445},{620, 760, 610, 445},{770, 910, 610, 445} };
	//��drawtext������outtextxy������ʵ�����ֵľ���
	settextcolor(BLACK);
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	

	/*
	char FirstSelect1[20] = { "����Ա��¼" };
	char FirstSelect2[20] = { "���������ߵ�¼" };
	char FirstSelect3[20] = { "�û�ע��/��¼" };
	DrawBotton(470, 400, 610, 445, 228, 228, 228, 400, 400, 400, 228, 228, 228, FirstSelect1, FirstSelect1, FirstSelect1, 0);
	*/

	while (1)
	{
		//get the mouce position and operation
		m1 = GetMouseMsg();
		//admin login botton
		if (m1.x > 470 && m1.x < 610 && m1.y > 400 && m1.y < 445)
		{
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				//���й���Ա��¼
				AdminSighIn();
			}
		}
		//volunteer login botton
		if (m1.x > 620 && m1.x < 760 && m1.y > 400 && m1.y <= 445)
		{
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
			}
		}
		//user login botton
		if (m1.x > 770 && m1.x < 910 && m1.y > 400 && m1.y <= 445)
		{
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
			}
		}
	}
	

}