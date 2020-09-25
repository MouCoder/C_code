#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int a = 0;
	//方法1
	char* p = &a;
	printf("%d\n", *p);
	//方法2---有问题
	printf("%d\n", (char)a);
	return 0;
}