#define _CRT_SECURE_NO_WARNINGS 1
#include"QList.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	//初始化一个空队列
	q->_front = NULL;
	q->_rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//创建节点
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_next = NULL;
	//判断队列是否为空
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
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	//判断队列是否为空
	if (q->_front == NULL)
	{
		return;
	}
	QNode* head = q->_front;
	q->_front = q->_front->_next;
	free(head);
	head = NULL;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q);
	//判断队列是否为空,为空返回-1
	if (q->_front == NULL)
	{
		return -1;
	}
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return -1;
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	return 0;
}
// 销毁队列 
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

