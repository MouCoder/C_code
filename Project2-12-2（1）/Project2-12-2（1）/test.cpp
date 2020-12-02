#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	//������������г������ε����ֶ����0�����ս������ֻ�������ε������������Ľ�����ڽ���������ֳ��������ּ��ɡ�
	int retTwo = nums[0];
	//���������������ݽ�����򣬽������retTwo��
	for (int n = 1; n < numsSize; n++)
	{
		retTwo ^= nums[n];
	}
	//�ҳ�retTwo�Ķ������У�����һλΪ1��λ��Ϊ1����һλ������������һ���϶�Ϊ1һ���϶�Ϊ0��
	int loc = 1;
	while (1)
	{
		if ((retTwo & loc) == loc)
			break;
		loc <<= 1;
	}
	//�������飬�����������һλҲ��1������һ�𣬲���1�ķ�һ��ͽ��������ֿ��ˣ�Ȼ���ٷֱ����͵õ�����������
	int* ret = (int*)malloc(sizeof(int)* 2);
	ret[0] = 0;
	ret[1] = 0;
	while (numsSize)
	{
		if ((nums[numsSize - 1] & loc) == loc)
			ret[0] ^= nums[numsSize - 1];
		else
		{
			ret[1] ^= nums[numsSize - 1];
		}
		numsSize--;
	}
	*returnSize = 2;
	return ret;
}
int main()
{
	int nums[] = { 1, 2, 10, 4, 1, 4, 3, 3};
	int returnSize;
	int* ret = singleNumbers(nums,8,&returnSize);
	printf("%d %d\n",ret[0],ret[1]);
	return 0;
}