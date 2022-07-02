#pragma once
#include<graphics.h>
#include"Global.h"
#include"DrawItems.h"
#include"AdminPage.h"

void InfoPage();

void ReciManageMenu();

void VolManageMenu();

void EndResiManageMenu();

bool WriteVolMessageFile(TextExchange toadd);
bool WriteResMessageFile(TextExchange toadd);
bool ReadVolMessageFile();
bool ReadResMessageFile();
