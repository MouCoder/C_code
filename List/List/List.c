#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void test()
{
	ListNode* head = ListCreate();
	ListNode* find = NULL;
	ListPushBack(head,1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);
	ListPopBack(head);
	ListPopBack(head);
	ListPrint(head);
	ListPushFront(head, 0);
	ListPushFront(head, -1);
	ListPrint(head);
	ListPopFront(head);
	ListPopFront(head);
	ListPrint(head);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	find = ListFind(head, 5);
	printf("%d\n", find);
	find = ListFind(head, 4);
	printf("%d\n", find->_data);
	ListErase(find);
	ListPrint(head);

}
int main()
{
	test();
	return 0;
}