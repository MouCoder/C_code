#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newSListNode = (SListNode*)malloc(sizeof(SListNode));
	if (newSListNode == NULL)
	{
		printf("ÉêÇë½ÚµãÊ§°Ü\n");
		exit(-1);
	}
	newSListNode->data = x;
	newSListNode->next = NULL;
	return newSListNode;
}

void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* SLNode = plist;
	while (SLNode != NULL)
	{
		printf("%d->",SLNode->data);
		SLNode = SLNode->next;
	}
	printf("NULL\n");
}


void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* plist = *pplist;
	//ÉêÇë¿Õ¼ä
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* list = *pplist;
		//±éÀúÕÒµ½Á´±íµÄÎ²
		while (list->next != NULL)
		{
			list = list->next;
		}
		list->next = newNode;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* phead = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = phead;
	}
	else
	{
		phead->next = *pplist;
		*pplist = phead;
	}
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tail = *pplist;
	SListNode* preTail = *pplist;
	while (tail->next != NULL)
	{
		preTail = tail;
		tail = tail->next;
	}
	preTail->next = NULL;
	free(tail);
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* head = *pplist;
	*pplist = (*pplist)->next;
	free(head);
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* loc = plist;
	while (loc != NULL)
	{
		if (loc->data == x)
		{
			return loc;
		}
		loc = loc->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListEraseAfter(SListNode* pos)
{
	SListNode* posNext = pos->next;
	pos = pos->next;
	free(posNext);
}
void SListDestory(SListNode* plist)
{
	SListNode* del = plist;
	while (plist == NULL)
	{
		del = plist;
		plist = plist->next;
		free(del);
	}
}