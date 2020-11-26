#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int singleNumber(int* nums, int numsSize)
{
	//如果两个数相同，异或后的结果为0
	//本题利用异或的这一特点，将数组中的所有数据互相异或，出现两次的异或后都会变成0，最终只剩下一个出现1次的
	while (numsSize != 1)
	{
		*(nums+1) = (*nums) ^ (*(nums + 1));
		++nums;
		numsSize--;
	}
	return *nums;
}
int main()
{
	int nums[] = { 2,2,1};
	printf("%d\n",singleNumber(nums,3));
	return 0;
}