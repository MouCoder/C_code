#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void replace(int nums[],int numsSize)
{
	//‘≠µÿ÷√ªªÀ„∑®
	int i = 0;
	for (; i < numsSize; i++)
	{
		while (nums[i] != i)
		{
			if (nums[i] == nums[nums[i]])
			{
				continue;
			}
			int temp = nums[i];
			nums[i] = nums[temp];
			nums[temp] = temp;
		}
	}
}

int main()
{
	int num[] = { 0, 2, 5, 6, 3, 4, 1 };
	replace(num,7);
	for (int i = 0; i < 7; i++)
		printf("%d ",num[i]);
}