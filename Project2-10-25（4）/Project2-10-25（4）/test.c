#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	//����ռ�
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
	//����ϱ�û�з��أ������û���ҵ��������ʱreturnSize = 0,����ֵҲΪ0
	*returnSize = 0;
	return 0;
}
int main()
{
	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	return 0;
}