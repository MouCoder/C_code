#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_LENGTH 11

//栈的基本操作
typedef struct Stack
{
	int* a; 
	int size;
	int capacity;
}Stack;

//初始化栈
void StackInit(Stack* st);
//判断栈空
bool StackEmpty(Stack* st);
//入栈
void StackPush(Stack* st,int x);
//出栈
void StackPop(Stack* st);
//获取栈顶元素
int StackTop(Stack* st);
//销毁栈
void StackDstory(Stack* st);

//打印
void print(int* a, int n);
//交换数据
void swap(int* p1, int* p2);

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapCreate(int* a, int n);
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现

//三数取中
int GetMidIndex(int* a, int left, int right);
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a,int begin,int end);
void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现
void MergeArr(int* a, int begin1, int begin2, int end1, int end2, int* tmp);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);
