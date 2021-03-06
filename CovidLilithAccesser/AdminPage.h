#pragma once
#include"Global.h"
#include"DrawItems.h"
#include"InfoPage.h"
#include"CovidLilithAccesser.h"
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

void AdminPage();

void EndAdminButton();

void ReleaseInfo(int towards);

//需要添加的居民信息	
// 0成功 1冲突 2其他
int AddResident(resident toadd);

//需要添加的工作人员	
// 0成功 1冲突 2其他
int AddVolunteer(volunteer toadd);

//需要删除的居民的ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelResident(long residentID);

//需要删除的工作人员ID	
// 数据库中不存在返回false，存在且删除返回true
bool DelVolunteer(long volunteerID);

void JumpLines(int lines, FILE* fp);

//rewrite the file with the data in the memory
void SaveInResiModify();
void SaveInVolModify();

bool LoadResidentInfoFile();

bool LoadVolInfoFile();
