#pragma once
#include<graphics.h>
#include"Global.h"
#include"DrawItems.h"
#include"AdminPage.h"

void InfoPage();

void ReciManageMenu();
void NextPageButtonRes();
void LastPageButtonRes();
void AddResidentFront();
void DelResidentFront();
void ReWriteResFront();
void EndResiManageMenu();

void VolManageMenu();
void NextPageButtonVol();
void LastPageButtonVol();
void AddVolFront();
void DelVolFront();
void EndVolManageMenu();


bool WriteVolMessageFile(TextExchange toadd);
bool WriteResMessageFile(TextExchange toadd);
bool ReadVolMessageFile();
bool ReadResMessageFile();
