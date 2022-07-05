#pragma once
#include"Global.h"
#include<graphics.h>

void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar);
void DrawTextsSingle(rectProperties position, char* fonts, char* L_TEXT, int sizeOfChar, int weightOfChar, int italic, rgbColor textColor);
void CheckButton(MOUSEMSG m, rectProperties& Button, void (*doSth)(void), char* L_TEXT, int sizeOfChar);
void CheckButtonForInfoPage(MOUSEMSG m, rectProperties& Button, void (*doSth)(int, int), char* L_TEXT, int sizeOfChar, int type, int nowType);
void DrawLineButtonOfRes(rectProperties rect[], int sizeOfFont, resident* resinfo, MOUSEMSG m);
void DrawLineButtonOfResForVol(rectProperties rects[], int sizeOfFont, resident* resinfo, MOUSEMSG m);
void DrawLineButtonOfVol(rectProperties rects[], int sizeOfFont, volunteer* volinfo, MOUSEMSG m);
void DrawTextModule(MOUSEMSG m, std::vector<TextExchange>texts);
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y); //x为要载入图片的X坐标，y为Y坐标