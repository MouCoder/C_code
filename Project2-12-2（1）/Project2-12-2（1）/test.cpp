#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	//利用异或将数组中出现两次的数字都变成0，最终结果就是只出现依次的两个数字异或的结果，在将这个结果拆分成两个数字即可。
	int retTwo = nums[0];
	//将数组中所有数据进行异或，结果存入retTwo中
	for (int n = 1; n < numsSize; n++)
	{
		retTwo ^= nums[n];
	}
	//找出retTwo的二进制中，任意一位为1的位（为1的哪一位，在两个数中一个肯定为1一个肯定为0）
	int loc = 1;
	while (1)
	{
		if ((retTwo & loc) == loc)
			break;
		loc <<= 1;
	}
	//遍历数组，数组中如果这一位也是1的数放一起，不是1的放一起就将两个数分开了，然后再分别异或就得到了两个数。
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