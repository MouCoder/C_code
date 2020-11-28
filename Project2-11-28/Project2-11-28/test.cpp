#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int search(int* nums, int numsSize, int target){
	int start = 0;
	int end = numsSize - 1;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (nums[mid] < target)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}
	return -1;
}
int main()
{
	
	return 0;
}