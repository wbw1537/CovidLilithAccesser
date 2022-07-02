#pragma once
#include<graphics.h>
#include"Global.h"
#include"DrawItems.h"

void InfoPage();

void ReciManageMenu();

void VolManageMenu();

bool WriteVolMessageFile(TextExchange toadd);
bool WriteResMessageFile(TextExchange toadd);
bool ReadVolMessageFile();
bool ReadResMessageFile();
