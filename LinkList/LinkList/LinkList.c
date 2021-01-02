#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
	}
	return newNode;
}
// �������ӡ
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
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//�����ڵ�
	SListNode* buyNode = BuySListNode(x);
	//�������Ϊ�գ���ýڵ��Ϊ��һ���ڵ�
	if (*pplist == NULL)
	{
		*pplist = buyNode;
	}
	else
	{
		//�ҵ�β�����в���
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = buyNode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	//�����ڵ�
	SListNode* buyNode = BuySListNode(x);
	buyNode->next = *pplist;
	*pplist = buyNode;
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	//�ҵ�β���
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* head = *pplist;
	*pplist = (*pplist)->next;
	free(head);
	head = NULL;
}
// ���������
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
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	//�����ڵ�
	SListNode* buyNode = BuySListNode(x);
	SListNode* posNext = pos->next;
	pos->next = buyNode;
	buyNode->next = posNext;
}
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	pos->next = pos->next->next;
}