#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int strStr(char* haystack, char* needle)
{
	//感悟：不要轻易简写代码，高估自己的水平
	int ret = 0;
	if (*needle == '\0')
		return 0;
	while (*haystack)
	{
		char* src = needle;
		char* dst = haystack;
		if (*haystack == *needle)
		{
			while (*haystack == *needle && *needle && *haystack)
			{
				haystack++;
				needle++;
			}
			if (*needle == '\0')
			{
				return ret;
			}
			else
			{
				needle = src;
				haystack = dst + 1;
				ret++;
			}
		}
		else
		{
			*haystack++;
			ret++;
		}
	}
	return -1;
}
int searchInsert(int* nums, int numsSize, int target)
{
	int ret = 0;
	//注意：
	//1.在while循环中，如果将循环条件"ret < numsSize"放在"nums[ret] < target"后边可能会导致数组溢出的情况
	//2.将while语句直接写成"while (ret < numsSize && nums[ret++] < target)"时，由于[]的优先级较高，会导致ret先++在进行运算
	while (ret < numsSize && nums[ret] < target)
	/*{
		ret++;
	}*/
	if (ret == numsSize)
		return numsSize;
	else
		return ret;
}
int main()
{
	//searcheInsert
	/*int nums[] = {1,3,5,6};
	int target = 7;
	printf("%d\n",searchInsert(nums,4,target));*/

	//strStr
	char haystack[] = "mississippi";
	char needle[] = "issip";
	printf("%d\n", strStr(haystack, needle));
	return 0;
}