#pragma once
#include<stdio.h>
#include<string.h>

//���µ����㷨
void AdjustDown(int* heap, int root,int n);
//���ϵ����㷨
void AdjustUp(int* heap, int child, int n);
//�������µ����㷨�����ѣ�С�ѣ�
void HeapCreate(int* heap, int root, int n);
////����в���һ��Ԫ��
//void HeapPush(int* heap,int* n,int x);

//������
void HeapSort(int* heap, int n);