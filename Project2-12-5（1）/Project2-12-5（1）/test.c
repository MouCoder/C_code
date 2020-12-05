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
	//˼·���������������飬�ڴ�����λ��k��������ֳ������ֱַ�����

	//�������λ��k=numsSize������������k=0ʱ��������
	if (k == 0 || k%numsSize == 0)
		return;
	if (k > numsSize)
		k %= numsSize;
	//������������
	reverse(nums,numsSize);

	//����ǰk��Ԫ��
	reverse(nums, k);

	//����ʣ��Ԫ��
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