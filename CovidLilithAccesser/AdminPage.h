#pragma once
#include"DataStructures.h"
#include<graphics.h>
#include<stdio.h>

void AdminPage();

//��Ҫ��ӵľ�����Ϣ	
// 0�ɹ� 1��ͻ 2����
int AddResident(resident toadd){
	
}

//��Ҫ��ӵĹ�����Ա	
// 0�ɹ� 1��ͻ 2����
int AddVolunteer(volunteer toadd);

//��Ҫɾ���ľ����ID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelResident(long residentID);

//��Ҫɾ���Ĺ�����ԱID	
// ���ݿ��в����ڷ���false��������ɾ������true
bool DelVolunteer(long volunteerID);

void JumpLines(int lines, FILE * fp);