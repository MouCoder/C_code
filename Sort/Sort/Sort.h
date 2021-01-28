#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_LENGTH 11

//ջ�Ļ�������
typedef struct Stack
{
	int* a; 
	int size;
	int capacity;
}Stack;

//��ʼ��ջ
void StackInit(Stack* st);
//�ж�ջ��
bool StackEmpty(Stack* st);
//��ջ
void StackPush(Stack* st,int x);
//��ջ
void StackPop(Stack* st);
//��ȡջ��Ԫ��
int StackTop(Stack* st);
//����ջ
void StackDstory(Stack* st);

//��ӡ
void print(int* a, int n);
//��������
void swap(int* p1, int* p2);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapCreate(int* a, int n);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��

//����ȡ��
int GetMidIndex(int* a, int left, int right);
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a,int begin,int end);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeArr(int* a, int begin1, int begin2, int end1, int end2, int* tmp);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);
