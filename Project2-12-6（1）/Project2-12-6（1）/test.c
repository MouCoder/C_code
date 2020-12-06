#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void test()
{
	SListNode* SListNode = NULL;
	SListPushBack(&SListNode, 1);
	SListPushBack(&SListNode, 2);
	SListPushBack(&SListNode, 3);
	SListPushBack(&SListNode, 4);
	SListPushFront(&SListNode, 0);
	SListPopBack(&SListNode);
	SListPopFront(&SListNode);

	SListPrint(SListNode);
	if (SListFind(SListNode, 3) == NULL)
		printf("没有这个值\n");
	else
		printf("找到了\n");
}

int main()
{
	test();
	return 0;
}

