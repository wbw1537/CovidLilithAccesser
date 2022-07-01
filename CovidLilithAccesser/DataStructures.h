#pragma once

//carify the width and height of the window
const int WINDOWWIDTH = 960;
const int WINDOWHEIGHT = 540;

//the struct of the RGB
typedef struct{
	int red, green, blue;
}rgbColor;

//the info if admin
typedef struct{
	char ID[64];
	char passWd[64];
	char name[64];
}ADM;

//struct of button
typedef struct {
	//the coordination of the rectangle
	int left, top, right, buttom;
	//the activity of mouce, 0 for not in, 1 for in it, 2 for chicking it
	int mouceActiv;
	//the mouceActive in the last loop
	int mouceActivBefore;
}rectProperties;

/*name:名字，passwd：密码， ID：用户ID*/
typedef struct {
	char name[50];
	char passwd[128];
	char fromProvince[32];
	long ID;
	//private
	bool ifRead;
	bool ifRisky;

}resident;

/*name：名字 passwd：密码 ID：工号*/
typedef struct {
	char name[50];
	char passwd[128];
	long ID;
}volunteer;