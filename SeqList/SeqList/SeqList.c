#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

// 顺序表初始化
void SeqListInit(SeqList* psl, int capacity)
{
	//申请空间
	psl->array = (SLDataType*)malloc(sizeof(SeqList)*capacity);
	//判断申请空间是否成功
	if (psl == NULL)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	psl->size = 0;
	psl->capicity = capacity;
}
// 顺序表销毁
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	//释放节点，置空指针
	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
		printf("%d ",psl->array[i]);
	printf("\n");
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	//顺序表已经满了，进行扩容,扩容后的顺序表的大小时原来的两倍
	if (psl->size == psl->capicity)
	{
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SeqList)*(psl->capicity) * 2);
		psl->capicity *= 2;
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	//检查顺序表是否还有容量，如果没有就进行扩容
	CheckCapacity(psl);
	//插入数据
	psl->array[psl->size] = x;
	//size+1
	psl->size++;
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	//判断顺序表是否为空
	if (psl->size == 0)
		return;
	//删除最后一个数据,即将有效数据个数-1
	psl->size--;
}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	//判断表的容量，如果不够则进行扩容
	CheckCapacity(psl);
	//如果表中的有效数据个数为0，则直接插入
	if (psl->size == 0)
		psl->array[psl->size] = x;
	else
	{
		//将有效元素后移一位，在将x插入
		int i = psl->size;
		for (; i > 0;i--)
		{
			psl->array[i] = psl->array[i - 1];
		}
		psl->array[0] = x;
	}
	//有效数据个数+1
	psl->size++;
}
// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	//判断有效数据个数，如果为0不进行任何操作
	if (psl->size == 0)
	{
		return;
	}
	//只有一个有效数据，则直接删除
	else if (psl->size == 1)
	{
		psl->size = 0;
	}
	else
	{
		int i = 0;
		//将后边元素前移一个位置
		for (; i < psl->size-1; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
		psl->size--;
	}
}
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	//判断表中有效元素是否为空
	assert(psl->size);
	int i = 0;
	//遍历顺序表，如果找到了返回对应的下标，如果没有找到返回-1
	for (; i < psl->size; i++)
	{
		if (psl->array[i] == x)
			return i;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	//判断顺序表容量
	CheckCapacity(psl);
	//判断插入位置是否合法
	if (pos < 0 || pos > psl->size)
	{
		printf("插入位置不合法\n");
		return;
	}
	int i = psl->size;
	//移动从pos开始的数据，后移一个位置
	for (; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, int pos)
{
	assert(psl);
	//判断删除位置是否合法
	if (pos < 0 || pos > psl->size)
	{
		printf("删除位置不合法\n");
		return;
	}
	else
	{
		int i = pos + 1;
		for (; i < psl->size; i++)
		{
			psl->array[i - 1] = psl->array[i];
		}
		psl->size--;
	}

}