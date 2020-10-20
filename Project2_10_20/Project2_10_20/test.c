#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
/**
*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
*你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
*示例:给定 nums = [2, 7, 11, 15], target = 9
*	 因为 nums[0] + nums[1] = 2 + 7 = 9
*	 所以返回 [0, 1]
*/

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	//假设给定的数组是一个有序数组，
	//随着数组下标的增大，数组元素逐渐增大
	int *a = (int*)malloc(sizeof(int)* 2);
	//判断调用者是否给returnSize分配空间
	//if (returnSize)
	//{
	//	//给returnSize分配两个整型大小的空间
	//	returnSize = (int*)malloc(sizeof(int)* 2);
	//}
	//假设第一个数的下标是0
	*returnSize = 0;
	a[0] = 0;
	while(a[0] < numsSize - 1)
	{
		a[1] = a[0] + 1;
		if (target - nums[a[0]] > nums[numsSize-1])
		{
			a[0]++;
		}
		else if (target - nums[a[0]] >= nums[a[1]])
		{
			while ((target - nums[a[0]] >= nums[a[1]]) && (a[1] <= numsSize-1))
			{
				if (target - nums[a[0]] == nums[a[1]])
				{
					*returnSize = 2;
					return a;
				}
				else
				{
					a[1]++;
				}
			}
			a[0]++;
		}
	}
	*returnSize = 2;
	return a;
}

