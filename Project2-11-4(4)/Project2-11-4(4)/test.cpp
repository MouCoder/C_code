#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	//删除排序数组中的重复项
	//将不重复的数据覆盖掉
	int loc = 0;//标记当前位置
	int mov = loc +1;//移动查找
	int flag = 0;//标记当前有效元素位置
	while (mov < numsSize)
	{
		if (nums[loc] != nums[mov])
		{
			nums[flag] = nums[loc];
			flag++;
			loc = mov;
			mov++;
		}
		//如果两个数重复，就继续往后走，直到找到不重复的将前边重复的覆盖掉。
		while (mov != numsSize && nums[loc] == nums[mov])
		{
			mov++;
		}
	}
	nums[flag] = nums[loc];
	return flag+1;
}
int main()
{
	int num[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int i = removeDuplicates(num, 10);
	for (int j = 0; j < i; j++)
		printf("%d ",num[j]);
	return 0;
}