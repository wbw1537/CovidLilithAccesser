#include"CovidLilithAccesser.h"

//load the login page
void LoadLoginPage() {
	IMAGE backGround;
	IMAGE logo;
	loadimage(&backGround, "resources / backGround.png", 960, 540);

	putimage(0, 0, &backGround);
}