#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void test()
{
	Stack p;
	StackInit(&p);
	StackPush(&p,1);
	StackPush(&p, 2);
	StackPush(&p, 3);
	StackPush(&p, 4);
	StackSize(&p);
	StackPop(&p);
	StackSize(&p);
	StackPop(&p);
	StackSize(&p);
	StackPop(&p);
	StackPop(&p);
}
int main()
{
	test();
	return 0;
}