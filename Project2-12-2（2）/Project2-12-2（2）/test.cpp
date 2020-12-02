#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int missingNumber(int* nums, int numsSize){
	int max = 0;
	int flag = 0;
	int sum = 0;
	//找出数组中最大的数，利用等差数列公式计算出从0~n的累加，
	//在将数组中的元素相加。用累加结果减去数组中元素的和就是结果，同时还要判断数组中有没有0
	while (numsSize)
	{
		if (nums[numsSize - 1] == 0)
			flag = 1;
		sum += nums[numsSize - 1];
		max = max < nums[numsSize - 1] ? nums[numsSize - 1] : max;
		numsSize--;
	}
	int ret = max + (max*(max - 1)) / 2;
	if (flag == 0)
		return 0;
	else if (ret == sum)
		return max + 1;
	else
		return ret - sum;
}
int main()
{
	int nums[] = {3,0,1};
	printf("%d\n",missingNumber(nums,3));
	return 0;
}