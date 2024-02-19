#include"content.h"

//1：动态开辟成员列表
//2：保存列表文件

void menu()
{
	printf("-----------------\n");
	printf("0.Exit\n");
	printf("1.Add\n");
	printf("2.Delete\n");
	printf("3.show\n");
	printf("4.search\n");
	printf("-----------------\n");
}

int main()
{
	int input;
	memlist memberlist1;
	listInitialize(&memberlist1);


	void (*pointList[5])(memlist * list) = {
		0,
		addMember,
		deleteMember,
		showList,
		searchMember };
	//转移表
	
	do
	{
		menu();
		printf("pleasr enter:");
		scanf_s("%d", &input);
		if (input)
			pointList[input](&memberlist1);

	} while (input);

	exitBook(&memberlist1);
	
	return 0;
}


	