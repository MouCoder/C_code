#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//创建一个节点
ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newNode->_next = newNode;
	newNode->_prev = newNode;
	return newNode;
}
// 双向链表销毁
void ListDestory(ListNode* plist)
{
	assert(plist);
	ListNode* curr= plist;
	while (curr != plist)
	{
		ListNode* del = curr;
		curr = curr->_next;
		free(del);
	}
	plist = NULL;
}
// 双向链表打印
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* curr = plist->_next;
	while (curr != plist)
	{
		printf("%d ", curr->_data);
		curr = curr->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	//创建一个节点
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = plist;
	buyNode->_prev = plist->_prev;
	plist->_prev->_next = buyNode;
	plist->_prev = buyNode;
}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	ListNode* tail = plist->_prev;
	plist->_prev->_prev->_next = plist;
	plist->_prev = plist->_prev->_prev;
	free(tail);
	tail = NULL;
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	//创建一个节点
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = plist->_next;
	plist->_next->_prev = buyNode;
	plist->_next = buyNode;
	buyNode->_prev = plist;
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	ListNode* head = plist->_next;
	plist->_next->_next->_prev = plist;
	plist->_next = plist->_next->_next;
	free(head);
	head = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	ListNode* curr = plist->_next;
	while (curr != plist)
	{
		if (curr->_data == x)
			return curr;
		curr = curr->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	//创建一个节点
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = pos;
	buyNode->_prev = pos->_prev;
	pos->_prev->_next = buyNode;
	pos->_prev = buyNode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* erase = pos;
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(erase);
	erase = NULL;
}