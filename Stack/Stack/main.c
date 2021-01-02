#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*2);
	ps->_capacity = 5;
	ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//判断栈是否满了，如果满了先进行增容在入栈
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)*(ps->_capacity));
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	//判断栈是否为空，如果为空直接退出
	if (StackEmpty(ps))
		return;
	printf("%d ",ps->_a[ps->_top-1]);
	ps->_top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	//判断栈是否为空
	if (StackEmpty(ps))
		return -1;
	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !(ps->_top);
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
}