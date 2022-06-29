#include"CovidLilithAccesser.h"

//load the login page
void LoadLoginPage() {
	IMAGE backGround, logo;
	//load background image and logo image, then print them.
	loadimage(&backGround, "resources / backGround.png", 960, 540);
	loadimage(&logo, "resources/covidProofWorkers.jpg");
	putimage(0, 0, &backGround);
	putimage(0, 0, &logo);
}