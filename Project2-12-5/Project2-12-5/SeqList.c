#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	//初始化开辟5个整型空间
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)* 5);
	ps->size = 0;
	ps->capacity = 5;
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	size_t i = 0;
	for (; i < ps->size; i++)
		printf("%d ",(ps->a)[i]);
	printf("\n");
}
void SeqListCreateCapacity(SeqList* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->a = (SLDateType*)realloc(ps->a,sizeof(SLDateType)* (ps->capacity) * 2);
		ps->capacity *= 2;
	}
	if (ps->a == NULL)
	{
		printf("扩容失败！\n");
		exit(-1);
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCreateCapacity(ps);
	ps->a[ps->size] = x;
	(ps->size)++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCreateCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (int i = 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i+1;
	}
	return -1;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	SeqListCreateCapacity(ps);
	if (pos<0 || pos>ps->size)
	{
		printf("插入位置不合法");
		return;
	}
	for (int i = ps->size - 1; i >= (int)pos; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	for (int i = pos; i < (int)ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}