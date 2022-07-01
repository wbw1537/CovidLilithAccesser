#pragma once
#include"DataStructures.h"
#include<graphics.h>
void DrawButton(rectProperties position, rgbColor outTheButton, rgbColor inTheButton, rgbColor clickTheButton, char* L_TEXT, int sizeOfChar, int moucePosition, int moucePositionBefore);

void drawAlpha(IMAGE* picture, int  picture_x, int picture_y); //x为要载入图片的X坐标，y为Y坐标