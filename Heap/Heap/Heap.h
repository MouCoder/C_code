#pragma once
#include<stdio.h>
#include<string.h>

//向下调整算法
void AdjustDown(int* heap, int root,int n);
//向上调整算法
void AdjustUp(int* heap, int child, int n);
//利用向下调整算法创建堆（小堆）
void HeapCreate(int* heap, int root, int n);
////向堆中插入一个元素
//void HeapPush(int* heap,int* n,int x);

//堆排序
void HeapSort(int* heap, int n);