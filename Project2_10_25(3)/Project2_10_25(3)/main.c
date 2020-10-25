#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
int removeElement(int* nums, int numsSize, int val)
{

	//注意：
	//1.容易忽略最后一个数的判断，即将循环条件写成nums!=p,导致最后一个数没有进行判断
	//2.容易忽略题目所给条件，本题如果忽略“注意这五个元素可为任意顺序”将很难解决
	//3.此类问题（字符串、数组等的删除）若题目要求只能使用额外的O(1)的空间的情况下优先考虑使用指针
	//4.双指针解决问题时，优先考虑一个指向开始，一个指向结尾
	//5.在本题目中，容易忽略使用"int* p = nums + numsSize - 1;"让指针p指向数组末尾时，若数组的元素个数为0则会导致p指向的位置不是数组的末尾
	if (numsSize == 0 )
		return 0;
	else
	{
		int* p = nums + numsSize - 1;
		while (nums <= p)
		{
			if (*p == val)
			{
				p--;
				numsSize--;
			}
			else if (*nums == val)
			{
				*nums = *p;
				p--;
				numsSize--;
				nums++;
			}
			else
			{
				nums++;
			}
		}
		return numsSize;
	}
}
int main()
{
	int nums[] = { 3, 2, 2, 3 }, val = 3;
	printf("%d\n", removeElement(nums, 4, 3));
	return 0;
}