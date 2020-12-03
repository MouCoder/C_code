#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* printNumbers(int n, int* returnSize)
{
	int* ret = (int*)malloc(sizeof(int)*((int)(pow(10.0, n)-1)));
	int i = (int)(pow(10.0, n ))-1;
	*returnSize = i;
	while (i)
	{
		ret[i - 1] = i;
		i--;
	}
	return ret;
}
int main()
{
	int n = 1;
	int returnSize;
	int* ret = printNumbers(n,&returnSize);
	return 0;
}
