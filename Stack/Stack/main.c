#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*2);
	ps->_capacity = 5;
	ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//�ж�ջ�Ƿ����ˣ���������Ƚ�����������ջ
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)*(ps->_capacity));
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	//�ж�ջ�Ƿ�Ϊ�գ����Ϊ��ֱ���˳�
	if (StackEmpty(ps))
		return;
	printf("%d ",ps->_a[ps->_top-1]);
	ps->_top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	//�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(ps))
		return -1;
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !(ps->_top);
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
}