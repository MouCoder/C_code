#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 1;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%4d", i);
			i += 2;
		}
		else i++;
	}
	return 0;
}