#include"CovidLilithAccesser.h"
#include"LoadLoginPage.h"

//load the login page
void LoadLoginPage() {
	
	IMAGE backGround, logo;
	//load background image and logo image, then print them.
	loadimage(&backGround, "resources/backGround.jpg");
	loadimage(&logo, "resources/covidProofWorkers.jpg",350,227);
	putimage(0, 0, &backGround);
	putimage(80, WINDOWHEIGHT / 2 - logo.getheight() / 2 - 20, &logo);

	
}