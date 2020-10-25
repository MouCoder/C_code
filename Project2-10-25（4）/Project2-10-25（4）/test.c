#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	//分配空间
	int* a = (int*)malloc(sizeof(int)* 2);
	int i, j;
	for (i = 0; i <= numsSize - 2;i++)
	for (j = i+1; j <= numsSize - 1; j++)
	{
		if (nums[i] + nums[j] == target)
		{
			a[0] = i;
			a[1] = j;
			*returnSize = 2;
			return a;
		}
	}
	//如果上边没有返回，则表明没有找到结果，此时returnSize = 0,返回值也为0
	*returnSize = 0;
	return 0;
}
int main()
{
	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	return 0;
}