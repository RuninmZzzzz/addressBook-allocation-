#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define MEMBER_MAX 15
#define NAME_MAX 10

#define INITIA_NUM 3
#define NUM_PER_ADD 2


typedef struct memberInformation meminfor;
typedef struct memberList memlist;

struct memberInformation
{
	char name[NAME_MAX];
	int telephone;
};

//��̬�汾
//struct memberList
//{
//	meminfor information [MEMBER_MAX];
//	int count;
//};

struct memberList
{
	meminfor* information;
	int count;
	int capacity;
};


//��ʼ��
void listInitialize(memlist* list);

//��ӳ�Ա
void addMember(memlist* list);

//��ӡ�б�
void showList(const memlist* list);

//ɾ����Ա
void deleteMember(memlist*  list);

//����
void searchMember(const memlist* list);

void exitBook(memlist* list);


