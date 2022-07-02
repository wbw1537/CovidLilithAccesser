#pragma once

#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>

#define AdminToResi 1
#define AdminToVol 2
#define VolToResi 3
#define VolToAdmin 4
#define ResiToVol 5
#define ResiToAdmin 6

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
	wchar_t belong[50];//belong to any volunteer
	unsigned int building;
	wchar_t district[128];
	//private
	int ifRead;
	int ifRisky;
}resident;

/*name：名字 passwd：密码 ID：工号*/
typedef struct {
	wchar_t name[50];
	char passwd[128];
	long ID;
	int age;
	int sex;
	wchar_t department[32];
	unsigned long long phone;
	wchar_t wechat[64];
	wchar_t position[32];
}volunteer;

typedef struct {
	int messageType;
	bool isSolve;
	char title[500];
	char message[500];
	char reply[500];
}TextExchange;

extern rgbColor colorOutOfTheButton;
extern rgbColor colorInTheButton;
extern rgbColor colorClickingTheButton;
extern rgbColor blueOfText;
extern rgbColor blackOfText;

extern char heiTi[64];
extern char songTi[64];

extern bool loadLoginPageOpen;

extern int numOfRes;
extern int numOfVol;

extern resident* residentInfo;
extern volunteer* volunteerInfo;
