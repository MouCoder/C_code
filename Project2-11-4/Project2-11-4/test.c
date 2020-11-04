#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


char *GetMemory(void)
{
	char* p = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}

void GetMemory2(char *p)
{
	p = (char *)malloc(100);
}
void Test2(void)
{
	char *str = NULL;
	GetMemory2(str);
	strcpy(str, "hello world");
	printf(str);
}
int main()
{
	char* p = "ab";
	return 0;
}