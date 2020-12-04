#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	SeqListPushFront(&s, 0);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	int i = SeqListFind(&s, 4);
	int j = SeqListFind(&s, 6);
	printf("%d,%d\n",i,j);

	SeqListInsert(&s, 0, 0);
	SeqListErase(&s, 0);
	SeqListPrint(&s);
}
int main()
{
	test();
	return 0;
}