#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//初始化栈
void StackInit(Stack* st)
{
	assert(st);

	//初始化5个空间的栈,本题中只需要两个
	st->a = (int*)malloc(sizeof(int)* 5);
	st->capacity = 5;
	st->size = 0;

}
//判断栈空
bool StackEmpty(Stack* st)
{
	return !(st->size);
}
//入栈
void StackPush(Stack* st, int x)
{
	assert(st);
	//如果栈满需要进行扩容，这里只需要两个空间即可，而所给栈有5个空间不存在栈满，这里就不进行扩容了。
	st->a[st->size] = x;
	(st->size)++;
}
//出栈
void StackPop(Stack* st)
{
	assert(st);
	//如果栈空，直接返回
	if (StackEmpty(st))
		return;

	(st->size)--;
}
//获取栈顶元素
int StackTop(Stack* st)
{
	//这里栈中元素为数组下标，因此一定是大于等于0的数，如果栈为空返回-1
	if (StackEmpty(st))
		return -1;
	return st->a[st->size-1];

}
//销毁栈
void StackDstory(Stack* st)
{
	assert(st);
	st->capacity = 0;
	st->size = 0;
	free(st->a);
}

//打印
void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
}
//交换数据
void swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	//算法思路：将数组中下标为i的元素插入到数组中[0,i-1]的有序区间中，使数组完全有序
	for (int i = 0; i < n-1; i++)
	{
		//将下标为i+1的元素跟[0,i]的元素进行比较，如果大于就将该元素后移，遇到小于的停止并将tmp插入
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	//算法思路：以gap为间隔进行插入排序,gap逐次减小，最后一趟gap为0（直接插入排序）
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap以三倍进行减小，为了保证最后一次是1所以要加1
		for (int i = 0; i < n - gap - 1; i++)
		{
			//以gap为间隔进行插入排序
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//将tmp插入到正确位置
			a[end + gap] = tmp;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	//算法思路：每次从数组中选出最大（小）的一个数放在数组的结尾（开头）。
	for (int i = 0; i < n - 1; i++)
	{
		int maxIndex = 0;
		for (int j = 0; j < n-i; j++)
		{
			if (a[j] > a[maxIndex])
			{
				maxIndex = j;
			}
		}
		swap(&a[n - 1-i], &a[maxIndex]);
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	//排升序，建大堆
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
			swap(&a[child], &a[parent]);
		else
			break;
		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapSort(int* a, int n)
{
	//建一个大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(a,n,i);

	//排序
	for (int i = 1; i < n; i++)
	{
		swap(&a[0], &a[n - i]);
		AdjustDwon(a, n - i, 0);
	}

}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchage = 0;
		//两两进行比较，将大数往后冒，一趟排将最大的数放在最后边
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				//如果第一趟排序没有任何数据交换，则证明已经有序不需要再进行排序
				exchage = 1;
			}
		}
		if (exchage == 0)
			break;
	}
}

// 快速排序递归实现

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (left > mid)
	{
		if (right > left)
			return left;
		else if (right < mid)
			return mid;
		else
			return right;
	}
	else
	{
		if (right > mid)
			return mid;
		else if (right < left)
			return left;
		else
			return right;
	}
}
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	//当数组中的数完全有序时，时间复杂度为O（N^2）,为了解决这个问题引入三数取中，让该情况下时间复杂度为O（N*logN）
	//三数取中是从最左边、最右边和中间这三个数中取出值处于中间位置的数与最右边的数进行交换。这样就将最坏的情况变成了最好的情况
	int midIndex = GetMidIndex(a,left,right);
	swap(&a[right],&a[midIndex]);

	int keyIndex = right;
	while (left < right)
	{
		//左边找到比key值大的数停下来
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		//右边找比key小的值停下来
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		//左边找到的大的和右边找到的小的交换
		swap(&a[left],&a[right]);
	}
	//当left==right时，1.left右走走到right位置：right位置的值比keyindex大
	//2.right左走走到left位置时，因为left 比right早走，所以此时left已经找到比keyindex值大
	//此时left==right且大于keyindex，交换keyindex和left的值，完成一趟排序
	swap(&a[left],&a[keyIndex]);

	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	//先在最右边挖一个坑
	int key = a[right];

	while (left < right)
	{
		//左边找一个比key大的数填到右边的坑，左边形成一个新的坑
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
		//右边找一个比key小的数填到左边的坑，右边又形成一个新的坑
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
	}
	//让key填入最后的坑中，此时数组中可以左边的数都比他小右边的数都比它大
	a[left] = key;

	return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[begin], &a[end]);
	//curr找小，跟prev交换，大的curr往后走，prev 不动
	int cur = begin;
	int prev = cur - 1;
	while (cur <= end)
	{
		if (a[cur] <= a[end] && ++prev != cur)
			swap(&a[cur], &a[prev]);

		cur++;
	}
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	//左右指针法
	/*if (left >= right)
		return;
	int div= PartSort1(a,left,right);
	QuickSort(a,left,div-1);
	QuickSort(a,div+1,right);*/
	
	//挖坑法
	/*if (left >= right)
		return;
	int div = PartSort2(a,left,right);
	QuickSort(a,left,div-1);
	QuickSort(a,div+1,right);*/

	//前后指针法
	if (left >= right)
		return;
	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	//定义一个栈并初始化
	Stack st;
	StackInit(&st);

	//让left和right入栈
	StackPush(&st,right);
	StackPush(&st,left);
	//当栈不为空时，就一直进行快速排序
	while (!StackEmpty(&st))
	{
		//让栈中的left和right之间的数进行一趟快速排序
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort1(a,begin,end);
		//判断div的左右两侧是否还需要继续进行快速排序
		if (div + 1 < end)
		{
			StackPush(&st,end);
			StackPush(&st,div+1);
		}
		if (div - 1 > begin)
		{
			StackPush(&st,div-1);
			StackPush(&st,begin);
		}
	}

	//销毁栈
	StackDstory(&st);
}

// 归并排序递归实现

//合并数组
void MergeArr(int* a,int begin1,int begin2,int end1,int end2,int* tmp)
{
	int left = begin1;
	int right = end2;
	int index = begin1;
	//先遍历两个数组，每次选较小的数放入tmp中，当其中一个数组遍历完停止
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//将另一个没有被遍历完的数组直接拷贝到数组中
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	//把归并好（排完序）数组在拷贝到原数组中
	for (int i = left; i <= right; i++)
		a[i] = tmp[i];

}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//当数组分解到不可在分解时停止
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//将分解后的数组两部分在进行分解
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);

	//合并数组
	MergeArr(a,left,mid+1,mid,right,tmp);
}
void MergeSort(int* a, int n)
{
	//开一个额外的数组空间
	int* tmp = (int*)malloc(sizeof(int)*n);

	//将数组进行拆解
	_MergeSort(a,0,n-1,tmp);

	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	//思路：逆向思维，取消归并排序的分解过程，从单独数据开始直接利用循环进行合并
	int* tmp = (int*)malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//如果只有左部分没有又部分就不在合并
			if (i + gap >= n)
				break;
			//右部分的数个数不够，调整右部分的右边界
			if (i+2*gap-1 >= n)
				MergeArr(a, i, i + gap, i + gap - 1, n-1, tmp);
			else
				MergeArr(a, i, i + gap, i + gap - 1, i + 2 * gap - 1, tmp);
		}
		gap *= 2;
	}
}

// 计数排序
void CountSort(int* a, int n)
{
	//找到最大数和最小数
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
		min = a[i];
	}
	//开辟数组max-min+1
	int* tmp = (int*)malloc(sizeof(int)*(max-min+1));
	memset(tmp,0,sizeof(int)*(max-min+1));
	//统计个数
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	//排序拷贝
	int index = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (tmp[i])
		{
			a[index++] = i + min;
			tmp[i]--;
		}
	}
}
