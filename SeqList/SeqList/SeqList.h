#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	int size; // 有效数据个数
	int capicity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, int capacity);
// 顺序表销毁
void SeqListDestory(SeqList* psl);
// 顺序表打印
void SeqListPrint(SeqList* psl);
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl);
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
// 顺序表尾删
void SeqListPopBack(SeqList* psl);
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);
// 顺序表头删
void SeqListPopFront(SeqList* psl);
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, int pos);