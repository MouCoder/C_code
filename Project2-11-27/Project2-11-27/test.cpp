#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* singleTwoNumber(int* nums, int numsSize)
{
	int a = 0,b = 1;
	int numsLength = numsSize;
	int ret[2] = {0};
	int loc = 0;
	while (numsLength)
	{
		a ^= *(nums++);
		numsLength--;
	}
	nums -= numsSize;
	while (1)
	{
		if (b == (b&a))
			break;
		b = b << 1;
	}
	while (numsSize)
	{
		if (((*nums)&b) == b)
		{
			ret[0] ^= (*nums);
		}
		else
			ret[1] ^= (*nums);
		nums++;
		numsSize--;
	}
	return ret;
}
int main()
{
	int num[] = {1,2,5,3,2,8,1,3,8,9};
	int* ret = singleTwoNumber(num, 10);
	printf("%d %d\n",ret[0],ret[1]);
	return 0;
}