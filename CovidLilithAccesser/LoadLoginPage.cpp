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

	rectProperties adminButton, volunteerButton, userButton;

	adminButton = { 470,400,610,445, 0 };
	volunteerButton = { 620, 400, 760, 445, 0 };
	userButton = { 770, 400, 910, 445, 0 };

	/*
	setfillcolor(RGB(228, 228, 228));
	fillrectangle(470, 400, 610, 445);
	fillrectangle(620, 400, 760, 445);
	fillrectangle(770, 400, 910, 445);
	setbkmode(TRANSPARENT);

	LOGFONT f;
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("宋体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	f.lfHeight = 20;
	settextstyle(&f);
	char FirstSelect1[20] = { "管理员登录" };
	char FirstSelect2[20] = { "社区工作者登录" };
	char FirstSelect3[20] = { "用户注册/登录" };
	RECT R[3] = { {470, 400, 610, 445},{620, 760, 610, 445},{770, 910, 610, 445} };
	//用drawtext而不是outtextxy，可以实现文字的居中
	settextcolor(BLACK);
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	*/

	
	char FirstSelect1[20] = { "管理员登录" };
	char FirstSelect2[20] = { "社区工作者登录" };
	char FirstSelect3[20] = { "用户注册/登录" };
	//DrawButton(470, 400, 610, 445, 228, 228, 228, 400, 400, 400, 228, 228, 228, FirstSelect1, FirstSelect1, FirstSelect1, 0);
	

	while (1)
	{
		//get the mouce position and operation
		m1 = GetMouseMsg();
		
		//init the mouce activity to not in
		adminButton.mouceActiv = 0;
		volunteerButton.mouceActiv = 0;
		userButton.mouceActiv = 0;
		
		//judge if the mouce in the button
		if (m1.x > adminButton.left && m1.x < adminButton.right && m1.y > adminButton.top && m1.y < adminButton.buttom){
			adminButton.mouceActiv = 1;
			if (m1.uMsg == WM_LBUTTONDOWN){
				adminButton.mouceActiv = 2;
				//进行管理员登录
				AdminSighIn();
			}
		}

		//draw the admin login Button
		DrawButton(adminButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, FirstSelect1, 18, adminButton.mouceActiv);
		
		//draw the volunteer login Button
		if (m1.x > volunteerButton.left && m1.x < volunteerButton.right && m1.y > volunteerButton.top && m1.y < volunteerButton.buttom){
			volunteerButton.mouceActiv = 1;
			if (m1.uMsg == WM_LBUTTONDOWN){
				volunteerButton.mouceActiv = 2;
				//VolunteerSignIn();
			}
		}
		//draw the volunteer login button
		DrawButton(volunteerButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, FirstSelect2, 18, volunteerButton.mouceActiv);

		//user login Button
		if (m1.x > userButton.left && m1.x < userButton.right && m1.y > volunteerButton.top && m1.y < volunteerButton.buttom){
			userButton.mouceActiv = 1;
			if (m1.uMsg == WM_LBUTTONDOWN){
				userButton.mouceActiv = 2;
				//VolunteerSignIn();
			}
		}
		//draw the user login button
		DrawButton(userButton, colorOutOfTheButton, colorInTheButton, colorClickingTheButton, FirstSelect3, 18, userButton.mouceActiv);

	}
	

}