#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkListNode
{
	int data;
	LinkListNode* next;
}LinkList;


//带头节点的单链表，带头结点的单链表和不带头结点的单链表的本质区别在于初始化
void LinkListInit(LinkList** list);

//建立单链表-->头插、尾插
void LinkListCraete_tail(LinkList** list);
void LinkListCraete_head(LinkList** list);

//增->位置、值
void LinkListAdd_value(LinkList** list);
void LinkListAdd_loc(LinkList** list);
//删->值
void LinkListDel_value(LinkList** list);
//查->值、位置
void LinkListSear_loc(LinkList* list);
//改->loc
void LinkListUpdate_loc(LinkList** list);
//length
void LinkListLength(LinkList* list);
void LinkListPrint(LinkList* list);