#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

// ˳����ʼ��
void SeqListInit(SeqList* psl, int capacity)
{
	//����ռ�
	psl->array = (SLDataType*)malloc(sizeof(SeqList)*capacity);
	//�ж�����ռ��Ƿ�ɹ�
	if (psl == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}
	psl->size = 0;
	psl->capicity = capacity;
}
// ˳�������
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	//�ͷŽڵ㣬�ÿ�ָ��
	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}
// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
		printf("%d ",psl->array[i]);
	printf("\n");
}
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	//˳����Ѿ����ˣ���������,���ݺ��˳���Ĵ�Сʱԭ��������
	if (psl->size == psl->capicity)
	{
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SeqList)*(psl->capicity) * 2);
		psl->capicity *= 2;
	}
}
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	//���˳����Ƿ������������û�оͽ�������
	CheckCapacity(psl);
	//��������
	psl->array[psl->size] = x;
	//size+1
	psl->size++;
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	//�ж�˳����Ƿ�Ϊ��
	if (psl->size == 0)
		return;
	//ɾ�����һ������,������Ч���ݸ���-1
	psl->size--;
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	//�жϱ������������������������
	CheckCapacity(psl);
	//������е���Ч���ݸ���Ϊ0����ֱ�Ӳ���
	if (psl->size == 0)
		psl->array[psl->size] = x;
	else
	{
		//����ЧԪ�غ���һλ���ڽ�x����
		int i = psl->size;
		for (; i > 0;i--)
		{
			psl->array[i] = psl->array[i - 1];
		}
		psl->array[0] = x;
	}
	//��Ч���ݸ���+1
	psl->size++;
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	//�ж���Ч���ݸ��������Ϊ0�������κβ���
	if (psl->size == 0)
	{
		return;
	}
	//ֻ��һ����Ч���ݣ���ֱ��ɾ��
	else if (psl->size == 1)
	{
		psl->size = 0;
	}
	else
	{
		int i = 0;
		//�����Ԫ��ǰ��һ��λ��
		for (; i < psl->size-1; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
		psl->size--;
	}
}
// ˳������
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	//�жϱ�����ЧԪ���Ƿ�Ϊ��
	assert(psl->size);
	int i = 0;
	//����˳�������ҵ��˷��ض�Ӧ���±꣬���û���ҵ�����-1
	for (; i < psl->size; i++)
	{
		if (psl->array[i] == x)
			return i;
	}
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	//�ж�˳�������
	CheckCapacity(psl);
	//�жϲ���λ���Ƿ�Ϸ�
	if (pos < 0 || pos > psl->size)
	{
		printf("����λ�ò��Ϸ�\n");
		return;
	}
	int i = psl->size;
	//�ƶ���pos��ʼ�����ݣ�����һ��λ��
	for (; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, int pos)
{
	assert(psl);
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (pos < 0 || pos > psl->size)
	{
		printf("ɾ��λ�ò��Ϸ�\n");
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