#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//	int nums[] = { 1, 1, 3, 5, 8, 2, 5, 6, 3, 8 };
//	//num1存储只出现依次的数在数组中的下标
//	int num1[2],count = 0;
//	int i, j;
//	//从0开始依次比较每一个数在数组中是否重复，如果找到与他重复的数就判断下一个数，如果没有找到就将这个数的下标保存，当两个数找够了就不在找了
//	for (i = 0; i < sizeof(nums) / sizeof(int); i++)
//	{
//		for (j = 0; j < sizeof(nums) / sizeof(int); j++)
//		{
//			if (nums[i] == nums[j] && j != i)
//				break;
//		}
//		if (j == sizeof(nums) / sizeof(int))
//		{
//			num1[count] = i;
//			count++;
//		}
//		if (count == 2)
//			break;
//	}
//	printf("nums[%d]:%d\nnums[%d]:%d\n",num1[0],nums[num1[0]],num1[1],nums[num1[1]]);
//	return 0;
//}
int my_atoi(const char * str)
{
	/*atoi的功能，给定一个由数字组成的字符串，将其转化成所表示的十进制数*/
	int i = strlen(str)-1;
	int ret = 0;
	int count = 1;
	for (; i >= 0; i--)
	{
		ret += (str[i] - '0')*count;
		count *= 10;
	}
	return ret;
}
int main()
{
	char* num = "73";
	printf("%d",my_atoi(num));

	return 0;
}