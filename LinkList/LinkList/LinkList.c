#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请内存失败！\n");
		exit(-1);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
	}
	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* curr = plist;
	while (curr)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//创建节点
	SListNode* buyNode = BuySListNode(x);
	//如果链表为空，则该节点就为第一个节点
	if (*pplist == NULL)
	{
		*pplist = buyNode;
	}
	else
	{
		//找到尾结点进行插入
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = buyNode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//创建节点
	SListNode* buyNode = BuySListNode(x);
	buyNode->next = *pplist;
	*pplist = buyNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	//找到尾结点
	SListNode* preTail = NULL;
	SListNode* tail = *pplist;
	while (tail->next)
	{
		preTail = tail;
		tail = tail->next;
	}
	preTail->next = NULL;
	free(tail);
	tail = NULL;
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* head = *pplist;
	*pplist = (*pplist)->next;
	free(head);
	head = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* curr = plist;
	while (curr)
	{
		if (curr->data == x)
			return curr;
		curr = curr->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	//创建节点
	SListNode* buyNode = BuySListNode(x);
	SListNode* posNext = pos->next;
	pos->next = buyNode;
	buyNode->next = posNext;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	pos->next = pos->next->next;
}