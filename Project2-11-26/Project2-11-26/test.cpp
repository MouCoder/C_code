#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int singleNumber(int* nums, int numsSize)
{
	//�����������ͬ������Ľ��Ϊ0
	//��������������һ�ص㣬�������е��������ݻ�����򣬳������ε����󶼻���0������ֻʣ��һ������1�ε�
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