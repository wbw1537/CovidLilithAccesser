#pragma once
#include"Global.h"
#include<graphics.h>

void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar);
void DrawTextsSingle(rectProperties position, char* fonts, char* L_TEXT, int sizeOfChar, int weightOfChar, int italic, rgbColor textColor);

void drawAlpha(IMAGE* picture, int  picture_x, int picture_y); //xΪҪ����ͼƬ��X���꣬yΪY����