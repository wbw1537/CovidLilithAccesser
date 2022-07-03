#include"Global.h"

extern rgbColor colorOutOfTheButton = { 209,209,209 };
extern rgbColor colorInTheButton = { 160,160,160 };
extern rgbColor colorClickingTheButton = { 120,120,120 };
extern rgbColor colorOfBackGround = { 249,249,249 };
extern rgbColor blueOfText = { 37,121,199 };
extern rgbColor blackOfText = { 30,30,30 };

extern char heiTi[64] = "ºÚÌå";
extern char songTi[64] = "ËÎÌå";

bool loadLoginPageOpen;
bool ResiManagePageOpen;
bool AdminPageOpen;
bool VolManagePageOpen;

/*
bool VolPageOpen;
bool loadLoginPageOpen;
*/

extern resident* residentinfo = { 0 };
extern volunteer* volunteerInfo = { 0 };
extern TextExchange* resMessageList = { 0 };
extern TextExchange* volMessageList = { 0 };
extern int numOfRes = 10;
extern int numOfVol = 10;
extern int indexToDrawPage = 0;
extern int lastIndexToDrawPage = 0;
extern bool forceToFlashButton = 0;