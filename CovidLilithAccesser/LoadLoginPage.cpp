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

	//load the button png and print.
	IMAGE loginAsUser, loginAsAdmin, loginAsVolunteer;
	loadimage(&loginAsUser, "resources/loginAsUser.png", 140, 45);
	loadimage(&loginAsAdmin, "resources/loginAsAdmin.png", 140, 45);
	loadimage(&loginAsVolunteer, "resources/loginAsVlounteer.png", 140, 45);
	drawAlpha(&loginAsAdmin, 470, 400);
	drawAlpha(&loginAsVolunteer, 620, 400);
	drawAlpha(&loginAsUser, 770, 400);


	/*
	fillroundrect(470, 400, 610, 445,140,45);
	fillroundrect(620, 760, 610, 445, 140, 45);
	fillroundrect(770, 910, 610, 445, 140, 45);
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
				//进行管理员登录
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