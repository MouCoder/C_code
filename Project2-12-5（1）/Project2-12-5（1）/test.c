#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(int* nums,int numsSize)
{
	int start = 0;
	int end = numsSize - 1;
	int mid;
	while (start < end)
	{
		mid = nums[start];
		nums[start] = nums[end];
		nums[end] = mid;
		start++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	//思路：先逆置整个数组，在从右移位数k处将数组分成两部分分别逆置

	//如果逆置位数k=numsSize的整数倍或者k=0时无需逆置
	if (k == 0 || k%numsSize == 0)
		return;
	if (k > numsSize)
		k %= numsSize;
	//逆置整个数组
	reverse(nums,numsSize);

	//逆置前k个元素
	reverse(nums, k);

	//逆置剩余元素
	reverse(nums+k,numsSize-k);
}
int main()
{
	int nums[] = { -1, -100, 3, 99 };
	int k = 2;
	int i;
	rotate(nums,sizeof(nums)/sizeof(nums[0]),k);
	for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
		printf("%d ",nums[i]);
	return 0;
}