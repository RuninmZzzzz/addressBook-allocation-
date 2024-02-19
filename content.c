#include"content.h"

void addCapacity(memlist* list)
{
	if (list->count >= list->capacity)
	{
		unsigned int subTemp = (list->count + NUM_PER_ADD) * sizeof(meminfor);
		meminfor* temp = realloc(list->information, subTemp);
		if (temp == NULL)
		{
			printf("addCapacity: %s\n", strerror(errno));
			return;
		}
		list->information = temp;
		list->capacity += NUM_PER_ADD;
		printf("Successful to add capavity\n");
	}
	return;
}


void saveBook(const memlist* list)
{
	FILE* fpWrite = fopen("MemberList.txt", "wb");
	if (fpWrite == NULL) {
		printf("saveBook: %s\n", strerror(errno));
		return;
	}
	fwrite(list->information, sizeof(meminfor), list->count, fpWrite);
}


void loadBook(memlist* list)
{
	FILE* fpRead = fopen("MemberList.txt", "rb");
	if (fpRead == NULL) {
		printf("loadBook: %s\n", strerror(errno));
		return;
	}
	int i = 0;
	meminfor Temp;
	while (fread(&Temp, sizeof(meminfor), 1, fpRead) == 1)
	{
		addCapacity(list);
		list->information[i++] = Temp;
		list->count++;
	}
}


//�����ֲ��ҳ�Ա�����س�Ա�±�
//�Ҳ�������-1
int seekByName(const memlist* list, char* name)
{
	int i = 0;
	for (i = 0; i < MEMBER_MAX; i++)
	{
		if (!strcmp(list->information[i].name, name))
			return i;
	}
	return -1;
}

//��ʼ��(��̬)
//void listInitialize(memlist* list)
//{
//	int i = sizeof(list->information);
//	memset(list, 0, sizeof(list->information));
//	list->count = 0;
//}

void listInitialize(memlist* list)
{
	list->information = (meminfor*)calloc(INITIA_NUM, sizeof(meminfor));
	list->count = 0;
	list->capacity = INITIA_NUM;

	loadBook(list);
}


void addMember(memlist* list)
{
	addCapacity(list);

	printf("enter member name:");
	scanf("%s", list->information[list->count].name);
	printf("enter member telephone:");
	scanf("%d", &(list->information[list->count].telephone));
	list->count++;
	
}

void showList(const memlist* list)
{
	int i = 0;
	printf("%-15s\t%-11s\n", "NAME", "TELEPHONE");
	for (i = 0; i < list->count; i++)
	{
		printf("%-15s\t%-11d",	list->information[i].name,
								list->information[i].telephone);
		printf("\n");
	}
}

void deleteMember(memlist* list)
{
	char tempName[NAME_MAX];
	printf("enter member name be delete:");
	scanf("%s", tempName);
	int judge = seekByName(list, tempName);
	//ɾ��judge�±��Ա
	if (judge > -1)
	{
		if (judge == MEMBER_MAX-1)
		{
			list->count--;
			return;
		}
		unsigned int justname1 = sizeof(list->information[0]) * (MEMBER_MAX - judge - 1);
		unsigned int justname2 = sizeof(list->information[0]);
		memmove(
			(void*)(list->information + judge),
			(void*)(list->information + judge + 1),
			sizeof(list->information[0]) * (MEMBER_MAX - judge-1));
		//ִ�к�ֵ��ķǳ���,��Ϊmemmove��list->count�ĵ�ַ��ֵ�ı���
		//�����memmove����������2024.1.31
		//2.19 ���²��ԣ������⣬��δ���޸�
		//�����⣬�����ݺ�ɾ����Ա�Ļ��������˳�ʱ����

		list->count--;
		return;
	}
	else
		printf("no fund member\n");	
}

void searchMember(const memlist* list)
{
	char tempName[NAME_MAX];
	printf("enter member name be search:");
	scanf("%s", tempName);
	int judge = seekByName(list, tempName);
	if (judge > -1 && judge < MEMBER_MAX)
	{
		printf("%-15s\t%-11d",	list->information[judge].name,
								list->information[judge].telephone);
		printf("\n");
		return;
	}
	printf("member be no finded\n");
}

void exitBook(memlist* list)
{
	//����
	saveBook(list);


	//����
	free(list->information);
	list->information = NULL;
}