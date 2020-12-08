#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	//如果只有1个或者没有元素，肯定不会存在重复，直接返回数组长度
	if (numsSize == 0 || numsSize == 1)
		return numsSize;
	int pre = 0;
	int curr = 1;
	int tag = 0;
	//如果有大于两个元素，就可能存在重复
	while (pre < numsSize - 1)
	{
		if (nums[pre] == nums[curr])
		{
			pre++;
			curr++;
		}
		else
		{
			nums[tag] = nums[pre];
			pre++;
			curr++;
			tag++;
		}
	}
	//执行完上面的代码，指针pre指向最后一个元素了，所以最后一个元素就没有进行存储
	nums[tag] = nums[pre];

	return tag + 1;
}

int main()
{
	return 0;
}
