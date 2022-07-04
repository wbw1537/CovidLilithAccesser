#pragma once
#include<graphics.h>
#include"Global.h"
#include"DrawItems.h"
#include"AdminPage.h"

void InfoPage(int type,int nowType);
void ExitButtonForAdminInfoPage();

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

bool WriteMessageFile(TextExchange toadd);
bool ReadMessageFile(TextExchange* MessageList, int type, int num);
