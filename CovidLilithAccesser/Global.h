#pragma once

#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>


//carify the width and height of the window
const int WINDOWWIDTH = 960;
const int WINDOWHEIGHT = 540;

//the struct of the RGB
typedef struct {
	int red, green, blue;
}rgbColor;

//the info if admin
typedef struct {
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
	wchar_t name[50];
	char passwd[128];
	wchar_t fromProvince[32];
	long ID;
	long belong;
	//private
	bool ifRead;
	bool ifRisky;

}resident;

/*name：名字 passwd：密码 ID：工号*/
typedef struct {
	wchar_t name[50];
	char passwd[128];
	long ID;
}volunteer;

extern rgbColor colorOutOfTheButton;
extern rgbColor colorInTheButton;
extern rgbColor colorClickingTheButton;
extern rgbColor blueOfText;
extern rgbColor blackOfText;

extern char heiTi[64];
extern char songTi[64];

extern bool loadLoginPageOpen;