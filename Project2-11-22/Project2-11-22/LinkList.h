#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkListNode
{
	int data;
	LinkListNode* next;
}LinkList;


//��ͷ�ڵ�ĵ�������ͷ���ĵ�����Ͳ���ͷ���ĵ�����ı����������ڳ�ʼ��
void LinkListInit(LinkList** list);

//����������-->ͷ�塢β��
void LinkListCraete_tail(LinkList** list);
void LinkListCraete_head(LinkList** list);

//��->λ�á�ֵ
void LinkListAdd_value(LinkList** list);
void LinkListAdd_loc(LinkList** list);
//ɾ->ֵ
void LinkListDel_value(LinkList** list);
//��->ֵ��λ��
void LinkListSear_loc(LinkList* list);
//��->loc
void LinkListUpdate_loc(LinkList** list);
//length
void LinkListLength(LinkList* list);
void LinkListPrint(LinkList* list);