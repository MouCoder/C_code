#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//����һ���ڵ�
ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newNode->_next = newNode;
	newNode->_prev = newNode;
	return newNode;
}
// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	//����һ���ڵ�
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = plist;
	buyNode->_prev = plist->_prev;
	plist->_prev->_next = buyNode;
	plist->_prev = buyNode;
}
// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	ListNode* tail = plist->_prev;
	plist->_prev->_prev->_next = plist;
	plist->_prev = plist->_prev->_prev;
	free(tail);
	tail = NULL;
}
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
	//����һ���ڵ�
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = plist->_next;
	plist->_next->_prev = buyNode;
	plist->_next = buyNode;
	buyNode->_prev = plist;
}
// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	ListNode* head = plist->_next;
	plist->_next->_next->_prev = plist;
	plist->_next = plist->_next->_next;
	free(head);
	head = NULL;
}
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	//����һ���ڵ�
	ListNode* buyNode = BuyNode(x);
	buyNode->_next = pos;
	buyNode->_prev = pos->_prev;
	pos->_prev->_next = buyNode;
	pos->_prev = buyNode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* erase = pos;
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(erase);
	erase = NULL;
}