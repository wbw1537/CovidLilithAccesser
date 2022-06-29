#include"CovidLilithAccesser.h"
#include"LoadLoginPage.h"
MOUSEMSG m1;
//load the login page
void LoadLoginPage() {
	
	IMAGE backGround, logo;
	//load background image and logo image, then print them.
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&logo, "resources/covidProofWorkers.jpg",350,227);
	putimage(0, 0, &backGround);
	putimage(80, WINDOWHEIGHT / 2 - logo.getheight() / 2 - 20, &logo);
	fillrectangle(270, 445, 370, 490);
	fillrectangle(390, 445, 490, 490);
	fillrectangle(510, 445, 610, 490);
}