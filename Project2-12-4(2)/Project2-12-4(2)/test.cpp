#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	//������������Ԫ�ض���Ŀ��ֵ�Ƚϣ���������ȣ������������һ��Ԫ�ز�����λ�ã��ڽ����鳤�ȼ�1
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