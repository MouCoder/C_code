#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//向下调整算法(小堆)
void AdjustDown(int* heap, int root,int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	//当父节点不在有子节点终止迭代（子节点超出数组下标）
	while (child+1 < n && child < n)
	{
		//选出较小的子节点
		if (heap[child] > heap[child + 1])
		{
			child = child + 1;
		}
		//比较父子节点大小关系
		if (heap[parent] > heap[child])
		{
			//交换父子节点
			int temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
		}
		else
		{
			//如果父节点小于子节点，提前退出程序，终止迭代
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

//向上调整算法
void AdjustUp(int* heap, int child, int n)
{
	//找到叶子节点的父节点
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//判断叶子节点是否小于父节点，小于就进行替换
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

//利用向下调整算法创建堆（小堆）
void HeapCreate(int* heap,int root,int n)
{
	//利用向下调整算法，从第一个非叶子结点开始调整。
	int i = (n - 2) / 2;
	for (; i >= root; i--)
	{
		AdjustDown(heap,i,n);
	}
}

//堆排序
void HeapSort(int* heap, int n)
{
	int m = n;
	int i = 1;
	//迭代n-1次
	for (i = 1; i < n; i++)
	{
		//交换堆根元素和最后一个叶子节点
		int temp = heap[m - 1];
		heap[m - 1] = heap[0];
		heap[0] = temp;
		//新堆大小减1
		m--;
		//对堆进行向下调整（最后一个叶子节点不进行调整）
		AdjustDown(heap, 0, m);
	}
}
////向堆中插入一个元素
//void HeapPush(int* heap, int* n,int x)
//{
//	//对数组进行扩容
//	heap = (int*)realloc(heap, sizeof(heap)+1 * sizeof(int));
//	heap[*n] = x;
//	*n++;
//	//向上调整
//	AdjustUp(heap,(*n)-1,*n);
//}