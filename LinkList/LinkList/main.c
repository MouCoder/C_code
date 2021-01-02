#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"
void test()
{
	SListNode* pList = NULL;
	SListNode* find = NULL;
	SListPushBack(&pList,1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	SListPushFront(&pList, 0);
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2); 
	SListPushFront(&pList, -3);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);
	find = SListFind(pList,4);
	printf("%d\n",find);
	find = SListFind(pList, 3);
	printf("%d\n", find->data);
	SListInsertAfter(find,4);
	SListPrint(pList);
	SListEraseAfter(find);
	SListPrint(pList);
}
int main()
{
	test();
	return 0;
}