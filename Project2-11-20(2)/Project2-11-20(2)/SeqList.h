#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h> 
#include<assert.h>
#include<stdlib.h>
#define MAX_SIZE 15
#define ElementType int

typedef struct SeqList
{
	ElementType* data;//˳����������
	int size;//˳����е����ݵĸ���
	int capacity;//˳��������
}SeqList;

void menue();
void init(SeqList* list);
bool ifFull(SeqList* list);
bool ifNull(SeqList* list);
void print(SeqList* list);
void SeqListInsertHead(SeqList* list,ElementType x);
void SeqListInsertTail(SeqList* list, ElementType x);
void SeqListRemoveHead(SeqList* list,int num);
void SeqListRemoveTail(SeqList* list, int num);
void SeqListRemoveLoc(SeqList* list,int loc);
int SeqListSize(SeqList* list);
void SeqListInsertLoc(SeqList* list, int loc, ElementType x);
void SeqListSort(SeqList* list);