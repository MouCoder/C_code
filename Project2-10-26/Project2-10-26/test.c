#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int strStr(char* haystack, char* needle)
{
	//���򣺲�Ҫ���׼�д���룬�߹��Լ���ˮƽ
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
	//ע�⣺
	//1.��whileѭ���У������ѭ������"ret < numsSize"����"nums[ret] < target"��߿��ܻᵼ��������������
	//2.��while���ֱ��д��"while (ret < numsSize && nums[ret++] < target)"ʱ������[]�����ȼ��ϸߣ��ᵼ��ret��++�ڽ�������
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