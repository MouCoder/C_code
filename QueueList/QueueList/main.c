#define _CRT_SECURE_NO_WARNINGS 1
#include"QList.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	//��ʼ��һ���ն���
	q->_front = NULL;
	q->_rear = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//�����ڵ�
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_next = NULL;
	//�ж϶����Ƿ�Ϊ��
	if (q->_front == NULL)
	{
		q->_front = newNode;
		q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}

}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	//�ж϶����Ƿ�Ϊ��
	if (q->_front == NULL)
	{
		return;
	}
	QNode* head = q->_front;
	q->_front = q->_front->_next;
	free(head);
	head = NULL;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q);
	//�ж϶����Ƿ�Ϊ��,Ϊ�շ���-1
	if (q->_front == NULL)
	{
		return -1;
	}
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return -1;
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* curr = q->_front;
	int size = 0;
	while (curr)
	{
		size++;
		curr = curr->_next;
	}
	return size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	return 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* curr = q->_front;
	QNode* del = NULL;
	while (curr)
	{
		del = curr;
		curr = curr->_next;
		free(del);
	}
	del = NULL;
}

