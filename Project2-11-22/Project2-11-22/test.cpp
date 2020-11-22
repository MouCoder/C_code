#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

/*
带头结点的单链表和不带头节点的单链表的区别在于，
带头结点的单链表进行创建操作时不需要考虑头结点的特殊处理，
而不太头结点的单链表需要对头结点进行单独处理
*/

int main()
{
	LinkList* s;
	LinkListInit(&s);
	LinkListCraete_head(&s);
	LinkListPrint(s);
	printf("\n------------------------\n");
	LinkListAdd_value(&s);
	LinkListAdd_loc(&s);
	LinkListDel_value(&s);
	LinkListSear_loc(s);
	LinkListUpdate_loc(&s);
	LinkListLength(s);
	LinkListPrint(s);
	
	return 0;
}