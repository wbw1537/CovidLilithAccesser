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
void ReWriteVolFront();
void EndVolManageMenu();

void ReciManageMenuForVol();
void EndResiManageMenuForVol();

void ReciManageMenuForResi();
void EndResiManageMenuForResi();

bool WriteVolMessageFile(TextExchange toadd);
bool WriteResMessageFile(TextExchange toadd);
bool ReadVolMessageFile();
bool ReadResMessageFile();
