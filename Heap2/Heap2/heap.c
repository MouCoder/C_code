#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//���µ����㷨,С��
void HeapAdjustDown(HPDataType* a,int root,int n)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//����Һ��ӽڵ���ڣ�ʹchildΪ���Һ����н�С�Ľڵ�
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			//�����ڵ�
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			//�ø��ڵ�������µ���
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//���ϵ����㷨��С��
void HeapAdjustUp(HPDataType* a, int child)
{
	int parent = (child - 2) / 2;
	//�����һ��Ҷ�ӽڵ㿪ʼ���ϵ���
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			//�����ڵ�
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
// �ѵĹ���С��
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	//���ٿռ�
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	//��������
	memcpy(hp->_a,a,sizeof(HPDataType)*n);
	//ʹ�����µ����㷨������,�ӵ�һ����Ҷ�ӽڵ㿪ʼ�������ζ����нڵ�ʹ�����µ����㷨��
	//��һ����Ҷ�ӽڵ�Ҳ�������һ��Ҷ�ӽڵ�ĸ��ڵ㣬���һ��Ҷ�ӽڵ���±�Ϊ:hp->_size-1���丸�ڵ�Ϊ��(hp->_size - 1 - 1)/2
	for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(hp->_a,i,hp->_size);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// �ѵĲ���
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
	//ʹ�����ϵ����㷨������
	HeapAdjustUp(hp->_a,hp->_size-1);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	//�Ѷ�Ԫ�������һ��Ҷ�ӽڵ㽻�����Զ����½������µ���
	assert(hp);
	int temp = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = hp->_a[0];
	hp->_a[0] = temp;
	//�Ѵ�С��1
	hp->_size--;
	//���µ����㷨�Զѽ��е���
	HeapAdjustDown(hp->_a,0,hp->_size);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	//�����Ϊ�շ���-1.���򷵻ضѶ�Ԫ��
	assert(hp);
	if (hp->_a == NULL)
	{
		return -1;
	}
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	//�����Ϊ�շ��ط�0��ֵ�����򷵻�0
	return !(hp->_size);
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	//�¶ѵĴ�С
	int size = n;
	//����������ɶ�
	for (int i = (n- 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(a, i, n);
	}
	while (size - 1)
	{
		//�����ѵĸ��ڵ�����һ��Ҷ�ӽڵ�
		int temp = a[0];
		a[0] = a[size - 1];
		a[size - 1] = temp;
		size--;
		//ʹ�����µ����㷨�Զѽ��е���
		HeapAdjustDown(a, 0, size);
	}
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	//��a��ȡK������������K������С��
	int* topK = (int*)malloc(sizeof(int)*k);
	memcpy(topK,a,sizeof(int)*k);
	//ʹ�����µ����㷨����С��
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(topK, i, k);
	}
	//����ԭ���飬��������е�Ԫ�ش��ڶѶ�Ԫ�ؾͽ����滻
	for (int i = k; i < n; i++)
	{
		if (a[i] > topK[0])
		{
			topK[0] = a[i];
			//������
			HeapAdjustDown(topK,0,k);
		}
	}
	printf("\nǰK�����Ϊ:");
	for (int i = 0; i < k; i++)
		printf("%d ",topK[i]);
	printf("\n");
}