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

//静态版本
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


//初始化
void listInitialize(memlist* list);

//添加成员
void addMember(memlist* list);

//打印列表
void showList(const memlist* list);

//删除成员
void deleteMember(memlist*  list);

//查找
void searchMember(const memlist* list);

void exitBook(memlist* list);


