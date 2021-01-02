#define _CRT_SECURE_NO_WARNINGS 1
#include"QList.h"
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d",QueueFront(&q));
	printf("%d", QueueBack(&q));
}
int main()
{
	test();
	return 0;
}