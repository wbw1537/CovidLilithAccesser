#pragma once

#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>

#define AdminToVol 1
#define VolToResi 2
#define VolToAdmin 3
#define ResiToVol 4

#define Administrator 1
#define Volunteer 2
#define Residente 3

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
	char name[50];
	char passwd[128];
	char fromProvince[32];
	long ID;
	char belong[50];//belong to any volunteer
	unsigned int building;
	char district[128];
	//private
	int ifRead;
	int ifRisky;
}resident;

/*name：名字 passwd：密码 ID：工号*/
typedef struct {
	char name[50];
	char passwd[128];
	long ID;
	int age;
	int sex;
	char department[50];//部门
	char phone[64];
	char wechat[64];
	char position[50];
}volunteer;

typedef struct {
	int messageType;
	int isSolve;
	char title[500];
	char message[500];
	char reply[500];
}TextExchange;

extern rgbColor colorOutOfTheButton;
extern rgbColor colorInTheButton;
extern rgbColor colorClickingTheButton;
extern rgbColor colorOfBackGround;
extern rgbColor blueOfText;
extern rgbColor blackOfText;

extern char heiTi[64];
extern char songTi[64];

extern bool loadLoginPageOpen;
extern bool ResiManagePageOpen;
extern bool AdminPageOpen;
extern bool ResiPageOpen;

extern int indexToDrawPage;
extern int lastIndexToDrawPage;
extern bool forceToFlashButton;
extern bool VolManagePageOpen;
extern bool VolPageOpen;
extern bool InfoPageOpen;
extern bool ReciManageMenuForVolOpen;
extern bool ResiManageMenuForResiOpen;

extern int numOfRes;
extern int numOfVol;

extern int numOfVolToResiMessage;
extern int numOfResiToVolMessage;
extern int numOfAdminToVolMessage;
extern int numOfVolToAdminMessage;

extern resident* residentInfo;
extern volunteer* volunteerInfo;
extern resident nowLoginResi;
extern volunteer nowLoginVol;
extern TextExchange* VolToResiMessageList;
extern TextExchange* ResiToVolMessageList;
extern TextExchange* VolToAdminMessageList;
extern TextExchange* AdminToVOlMessageList;