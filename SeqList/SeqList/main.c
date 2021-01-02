#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void test()
{
	int i;
	SeqList p;
	SeqListInit(&p,1);
	SeqListPushFront(&p,1);
	SeqListPushFront(&p, 2);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 4);
	SeqListPrint(&p);
	SeqListPopFront(&p);
	SeqListPrint(&p);
	i = SeqListFind(&p,4);
	printf("%d\n",i);
	i = SeqListFind(&p,1);
	printf("%d\n", i);

	SeqListInsert(&p,2,5);
	SeqListPrint(&p);
	SeqListErase(&p, 2);
	SeqListPrint(&p);
	SeqListDestory(&p);
}

int main()
{
	test();
	return 0;
}