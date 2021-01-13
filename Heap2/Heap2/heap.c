#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//向下调整算法,小堆
void HeapAdjustDown(HPDataType* a,int root,int n)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//如果右孩子节点存在，使child为左右孩子中较小的节点
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			//交换节点
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			//让父节点继续向下迭代
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整算法，小堆
void HeapAdjustUp(HPDataType* a, int child)
{
	int parent = (child - 2) / 2;
	//从最后一个叶子节点开始向上调整
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			//交换节点
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child-2) / 2;
	}
}
// 堆的构建小堆
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	//开辟空间
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	//复制数组
	memcpy(hp->_a,a,sizeof(HPDataType)*n);
	//使用向下调整算法构建堆,从第一个非叶子节点开始向上依次对所有节点使用向下调整算法。
	//第一个非叶子节点也就是最后一个叶子节点的父节点，最后一个叶子节点的下标为:hp->_size-1，其父节点为：(hp->_size - 1 - 1)/2
	for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(hp->_a,i,hp->_size);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity++;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType)*(hp->_capacity));
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//使用向上调整算法调整堆
	HeapAdjustUp(hp->_a,hp->_size-1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	//堆顶元素与最后一个叶子节点交换，对堆重新进行向下调整
	assert(hp);
	int temp = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = hp->_a[0];
	hp->_a[0] = temp;
	//堆大小减1
	hp->_size--;
	//向下调整算法对堆进行调整
	HeapAdjustDown(hp->_a,0,hp->_size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	//如果堆为空返回-1.否则返回堆顶元素
	assert(hp);
	if (hp->_a == NULL)
	{
		return -1;
	}
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	//如果堆为空返回非0的值，否则返回0
	return !(hp->_size);
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//新堆的大小
	int size = n;
	//将数组调整成堆
	for (int i = (n- 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(a, i, n);
	}
	while (size - 1)
	{
		//交换堆的根节点和最后一个叶子节点
		int temp = a[0];
		a[0] = a[size - 1];
		a[size - 1] = temp;
		size--;
		//使用向下调整算法对堆进行调整
		HeapAdjustDown(a, 0, size);
	}
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	//从a中取K个数建立含有K个数的小堆
	int* topK = (int*)malloc(sizeof(int)*k);
	memcpy(topK,a,sizeof(int)*k);
	//使用向下调整算法构建小堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(topK, i, k);
	}
	//遍历原数组，如果数组中的元素大于堆顶元素就进行替换
	for (int i = k; i < n; i++)
	{
		if (a[i] > topK[0])
		{
			topK[0] = a[i];
			//调整堆
			HeapAdjustDown(topK,0,k);
		}
	}
	printf("\n前K大个数为:");
	for (int i = 0; i < k; i++)
		printf("%d ",topK[i]);
	printf("\n");
}