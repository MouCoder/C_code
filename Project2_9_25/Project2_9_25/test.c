#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int a = 0;
	//����1
	char* p = &a;
	printf("%d\n", *p);
	//����2---������
	printf("%d\n", (char)a);
	return 0;
}