#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//��ʼ��ջ
void StackInit(Stack* st)
{
	assert(st);

	//��ʼ��5���ռ��ջ,������ֻ��Ҫ����
	st->a = (int*)malloc(sizeof(int)* 5);
	st->capacity = 5;
	st->size = 0;

}
//�ж�ջ��
bool StackEmpty(Stack* st)
{
	return !(st->size);
}
//��ջ
void StackPush(Stack* st, int x)
{
	assert(st);
	//���ջ����Ҫ�������ݣ�����ֻ��Ҫ�����ռ伴�ɣ�������ջ��5���ռ䲻����ջ��������Ͳ����������ˡ�
	st->a[st->size] = x;
	(st->size)++;
}
//��ջ
void StackPop(Stack* st)
{
	assert(st);
	//���ջ�գ�ֱ�ӷ���
	if (StackEmpty(st))
		return;

	(st->size)--;
}
//��ȡջ��Ԫ��
int StackTop(Stack* st)
{
	//����ջ��Ԫ��Ϊ�����±꣬���һ���Ǵ��ڵ���0���������ջΪ�շ���-1
	if (StackEmpty(st))
		return -1;
	return st->a[st->size-1];

}
//����ջ
void StackDstory(Stack* st)
{
	assert(st);
	st->capacity = 0;
	st->size = 0;
	free(st->a);
}

//��ӡ
void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
}
//��������
void swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// ��������
void InsertSort(int* a, int n)
{
	assert(a);
	//�㷨˼·�����������±�Ϊi��Ԫ�ز��뵽������[0,i-1]�����������У�ʹ������ȫ����
	for (int i = 0; i < n-1; i++)
	{
		//���±�Ϊi+1��Ԫ�ظ�[0,i]��Ԫ�ؽ��бȽϣ�������ھͽ���Ԫ�غ��ƣ�����С�ڵ�ֹͣ����tmp����
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

// ϣ������
void ShellSort(int* a, int n)
{
	//�㷨˼·����gapΪ������в�������,gap��μ�С�����һ��gapΪ0��ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap���������м�С��Ϊ�˱�֤���һ����1����Ҫ��1
		for (int i = 0; i < n - gap - 1; i++)
		{
			//��gapΪ������в�������
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
			//��tmp���뵽��ȷλ��
			a[end + gap] = tmp;
		}
	}
}

// ѡ������
void SelectSort(int* a, int n)
{
	//�㷨˼·��ÿ�δ�������ѡ�����С����һ������������Ľ�β����ͷ����
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

// ������
void AdjustDwon(int* a, int n, int root)
{
	//�����򣬽����
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
	//��һ�����
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(a,n,i);

	//����
	for (int i = 1; i < n; i++)
	{
		swap(&a[0], &a[n - i]);
		AdjustDwon(a, n - i, 0);
	}

}

// ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchage = 0;
		//�������бȽϣ�����������ð��һ���Ž���������������
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				//�����һ������û���κ����ݽ�������֤���Ѿ�������Ҫ�ٽ�������
				exchage = 1;
			}
		}
		if (exchage == 0)
			break;
	}
}

// ��������ݹ�ʵ��

//����ȡ��
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
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	//�������е�����ȫ����ʱ��ʱ�临�Ӷ�ΪO��N^2��,Ϊ�˽�����������������ȡ�У��ø������ʱ�临�Ӷ�ΪO��N*logN��
	//����ȡ���Ǵ�����ߡ����ұߺ��м�����������ȡ��ֵ�����м�λ�õ��������ұߵ������н����������ͽ��������������õ����
	int midIndex = GetMidIndex(a,left,right);
	swap(&a[right],&a[midIndex]);

	int keyIndex = right;
	while (left < right)
	{
		//����ҵ���keyֵ�����ͣ����
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		//�ұ��ұ�keyС��ֵͣ����
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		//����ҵ��Ĵ�ĺ��ұ��ҵ���С�Ľ���
		swap(&a[left],&a[right]);
	}
	//��left==rightʱ��1.left�����ߵ�rightλ�ã�rightλ�õ�ֵ��keyindex��
	//2.right�����ߵ�leftλ��ʱ����Ϊleft ��right���ߣ����Դ�ʱleft�Ѿ��ҵ���keyindexֵ��
	//��ʱleft==right�Ҵ���keyindex������keyindex��left��ֵ�����һ������
	swap(&a[left],&a[keyIndex]);

	return left;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	//�������ұ���һ����
	int key = a[right];

	while (left < right)
	{
		//�����һ����key�������ұߵĿӣ�����γ�һ���µĿ�
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
		//�ұ���һ����keyС�������ߵĿӣ��ұ����γ�һ���µĿ�
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
	}
	//��key�������Ŀ��У���ʱ�����п�����ߵ���������С�ұߵ�����������
	a[left] = key;

	return left;
}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[begin], &a[end]);
	//curr��С����prev���������curr�����ߣ�prev ����
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
	//����ָ�뷨
	/*if (left >= right)
		return;
	int div= PartSort1(a,left,right);
	QuickSort(a,left,div-1);
	QuickSort(a,div+1,right);*/
	
	//�ڿӷ�
	/*if (left >= right)
		return;
	int div = PartSort2(a,left,right);
	QuickSort(a,left,div-1);
	QuickSort(a,div+1,right);*/

	//ǰ��ָ�뷨
	if (left >= right)
		return;
	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	//����һ��ջ����ʼ��
	Stack st;
	StackInit(&st);

	//��left��right��ջ
	StackPush(&st,right);
	StackPush(&st,left);
	//��ջ��Ϊ��ʱ����һֱ���п�������
	while (!StackEmpty(&st))
	{
		//��ջ�е�left��right֮���������һ�˿�������
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort1(a,begin,end);
		//�ж�div�����������Ƿ���Ҫ�������п�������
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

	//����ջ
	StackDstory(&st);
}

// �鲢����ݹ�ʵ��

//�ϲ�����
void MergeArr(int* a,int begin1,int begin2,int end1,int end2,int* tmp)
{
	int left = begin1;
	int right = end2;
	int index = begin1;
	//�ȱ����������飬ÿ��ѡ��С��������tmp�У�������һ�����������ֹͣ
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//����һ��û�б������������ֱ�ӿ�����������
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	//�ѹ鲢�ã������������ڿ�����ԭ������
	for (int i = left; i <= right; i++)
		a[i] = tmp[i];

}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//������ֽ⵽�����ڷֽ�ʱֹͣ
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//���ֽ��������������ڽ��зֽ�
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);

	//�ϲ�����
	MergeArr(a,left,mid+1,mid,right,tmp);
}
void MergeSort(int* a, int n)
{
	//��һ�����������ռ�
	int* tmp = (int*)malloc(sizeof(int)*n);

	//��������в��
	_MergeSort(a,0,n-1,tmp);

	free(tmp);
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	//˼·������˼ά��ȡ���鲢����ķֽ���̣��ӵ������ݿ�ʼֱ������ѭ�����кϲ�
	int* tmp = (int*)malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//���ֻ���󲿷�û���ֲ��־Ͳ��ںϲ�
			if (i + gap >= n)
				break;
			//�Ҳ��ֵ������������������Ҳ��ֵ��ұ߽�
			if (i+2*gap-1 >= n)
				MergeArr(a, i, i + gap, i + gap - 1, n-1, tmp);
			else
				MergeArr(a, i, i + gap, i + gap - 1, i + 2 * gap - 1, tmp);
		}
		gap *= 2;
	}
}

// ��������
void CountSort(int* a, int n)
{
	//�ҵ����������С��
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
		min = a[i];
	}
	//��������max-min+1
	int* tmp = (int*)malloc(sizeof(int)*(max-min+1));
	memset(tmp,0,sizeof(int)*(max-min+1));
	//ͳ�Ƹ���
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	//���򿽱�
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
