#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	//，数组中所有元素都跟目标值比较，如果结果相等，将数组中最后一个元素补到该位置，在将数组长度减1
	for (int i = 0; i < numsSize;i++)
	if ((nums[i] ^ val) == 0)
	{
		nums[i] = nums[numsSize-1];
		i--;
		numsSize--;
	}
	return numsSize;
}
int main()
{
	int nums[] = {3,2,2,3};
	removeElement(nums,4,3);
	return 0;
}