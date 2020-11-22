#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

void LinkListInit(LinkList** list)
{
	*(list) = (LinkList*)malloc(sizeof(LinkListNode));
	(*list)->next = NULL;
}

void LinkListCraete_tail(LinkList** list)
{
	LinkList* p = *(list);
	int elemValue;
	do{
		scanf("%d",&elemValue);
		if (elemValue == 0)
			break;
		LinkList* sNode = (LinkList*)malloc(sizeof(LinkList));
		sNode->data = elemValue;
		sNode->next = NULL;
		p->next = sNode;
		p = p->next;
	} while (elemValue);
}

void LinkListCraete_head(LinkList** list)
{
	int elemValue;
	printf("input the value:>");
	do{
		scanf("%d",&elemValue);
		if (elemValue == 0)
			break;
		LinkList* sNode = (LinkList*)malloc(sizeof(LinkList));
		sNode->data = elemValue;
		sNode->next = (*list)->next;
		(*list)->next = sNode;
	} while (elemValue);
}

void LinkListAdd_value(LinkList** list)
{
	int elemValue;
	printf("input the value:>");
	scanf("%d",&elemValue);
	LinkList* sNode = (LinkList*)malloc(sizeof(LinkList));
	sNode->data = elemValue;
	LinkList* p = (*list);
	while ((p->next)->data < elemValue)
	{
		p = p->next;
	}
	sNode->next = p->next;
	p->next = sNode;
}
void LinkListAdd_loc(LinkList** list)
{
	int loc, elemValue;
	int i = 1;
	printf("input the loc and value:>");
	scanf("%d,%d",&loc,&elemValue);
	LinkList* p = (*list);
	LinkList* sNode = (LinkList*)malloc(sizeof(LinkList));
	sNode->data = elemValue;
	p = p->next;
	while (i < loc-1)
	{
		p = p->next;
		if (p == NULL)
		{
			printf("the loc error\n");
			return;
		}
		i++;
	}
	sNode->next = p->next;
	p->next = sNode;
}

void LinkListDel_value(LinkList** list)
{
	LinkList* p = (*list);
	int elemValue;
	printf("input the value:>");
	scanf("%d",&elemValue);
	while ((p->next)->data != elemValue)
	{
		p = p->next;
	}
	p->next = (p->next)->next;
}

void LinkListSear_loc(LinkList* list)
{
	int loc;
	printf("input the loc:>");
	scanf("%d",&loc);
	int i = 1;
	LinkList* p = list->next;
	while (i < loc && p != NULL)
	{
		p = p->next;
		i++;
	}
	printf("the value is:>%d\n",p->data);
}
void LinkListUpdate_loc(LinkList** list)
{
	int loc,value;
	printf("input the loc and value:>");
	scanf("%d,%d", &loc,&value);
	int i = 1;
	LinkList* p = (*list)->next;
	while (i < loc && p != NULL)
	{
		p = p->next;
		i++;
	}
	p->data = value;
}
void LinkListLength(LinkList* list)
{
	int length = 0;
	LinkList* p = list->next;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	printf("the length is:%d\n",length);
}
void LinkListPrint(LinkList* list)
{
	LinkList* p = list->next;
	while (p)
	{
		printf("%d ",p->data);
		p = p->next;
		
	}
}