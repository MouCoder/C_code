#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//���µ����㷨(С��)
void AdjustDown(int* heap, int root,int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	//�����ڵ㲻�����ӽڵ���ֹ�������ӽڵ㳬�������±꣩
	while (child+1 < n && child < n)
	{
		//ѡ����С���ӽڵ�
		if (heap[child] > heap[child + 1])
		{
			child = child + 1;
		}
		//�Ƚϸ��ӽڵ��С��ϵ
		if (heap[parent] > heap[child])
		{
			//�������ӽڵ�
			int temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
		}
		else
		{
			//������ڵ�С���ӽڵ㣬��ǰ�˳�������ֹ����
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

//���ϵ����㷨
void AdjustUp(int* heap, int child, int n)
{
	//�ҵ�Ҷ�ӽڵ�ĸ��ڵ�
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//�ж�Ҷ�ӽڵ��Ƿ�С�ڸ��ڵ㣬С�ھͽ����滻
		if (heap[child] < heap[parent])
		{
			int temp = heap[child];
			heap[child] = heap[parent];
			heap[parent] = temp;
		}
		else
		{
			break;
		}
	}
}

//�������µ����㷨�����ѣ�С�ѣ�
void HeapCreate(int* heap,int root,int n)
{
	//�������µ����㷨���ӵ�һ����Ҷ�ӽ�㿪ʼ������
	int i = (n - 2) / 2;
	for (; i >= root; i--)
	{
		AdjustDown(heap,i,n);
	}
}

//������
void HeapSort(int* heap, int n)
{
	int m = n;
	int i = 1;
	//����n-1��
	for (i = 1; i < n; i++)
	{
		//�����Ѹ�Ԫ�غ����һ��Ҷ�ӽڵ�
		int temp = heap[m - 1];
		heap[m - 1] = heap[0];
		heap[0] = temp;
		//�¶Ѵ�С��1
		m--;
		//�Զѽ������µ��������һ��Ҷ�ӽڵ㲻���е�����
		AdjustDown(heap, 0, m);
	}
}
////����в���һ��Ԫ��
//void HeapPush(int* heap, int* n,int x)
//{
//	//�������������
//	heap = (int*)realloc(heap, sizeof(heap)+1 * sizeof(int));
//	heap[*n] = x;
//	*n++;
//	//���ϵ���
//	AdjustUp(heap,(*n)-1,*n);
//}