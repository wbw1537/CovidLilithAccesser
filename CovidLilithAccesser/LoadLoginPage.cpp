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
	drawAlpha(&title, 500, 50);

	//load the button png and print.
	IMAGE loginAsUser, loginAsAdmin, loginAsVolunteer;
	loadimage(&loginAsUser, "resources/loginAsUser.png", 140, 45);
	loadimage(&loginAsAdmin, "resources/loginAsAdmin.png", 140, 45);
	loadimage(&loginAsVolunteer, "resources/loginAsVlounteer.png", 140, 45);
	drawAlpha(&loginAsAdmin, 470, 430);
	drawAlpha(&loginAsVolunteer, 620, 430);
	drawAlpha(&loginAsUser, 770, 430);

	/*
	//draw the rectangle for the login buttom
	fillrectangle(250, 445, 400, 490);
	fillrectangle(420, 445, 570, 490);
	fillrectangle(590, 445, 740, 490);
	setbkmode(TRANSPARENT);
	settextcolor(GREEN);
	char FirstSelect1[20] = { "管理员登录" };
	char FirstSelect2[20] = { "社区工作者登录" };
	char FirstSelect3[20] = { "居民登录" };
	RECT R[3] = { {250, 445, 400, 490},{420, 445, 570, 490},{590, 445, 740, 490} };
	drawtext(FirstSelect1, &R[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect2, &R[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(FirstSelect3, &R[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	*/
	

}