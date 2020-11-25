#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int search(int* nums, int numsSize, int target)
{
	int start, end, mid;
	start = 0;
	end = numsSize - 1;
	mid = (start + end) / 2;
	while (start <= end)
	{
		if (nums[mid] == target)
			return mid;
		else if (nums[start] == target)
			return start;
		else if (nums[end] == target)
			return end;
		if (nums[start] < nums[mid])
		{
			if ((target > nums[mid]) || (target < nums[start]))
			{
				start = mid + 1;
				mid = (start + end) / 2;
			}
			else
			{
				end = mid - 1;
				mid = (start + end) / 2;
			}
		}
		else
		{
			if ((target < nums[0]) && (target > nums[mid]))
			{
				start = mid + 1;
				mid = (start + end) / 2;
			}
			else
			{
				end = mid - 1;
				mid = (start + end) / 2;
			}
		}
	}
	return -1;
}

int main()
{
	int a[] = { 266, 267, 268, 269, 271, 278, 282, 292, 293, 298, 6, 9, 15, 19, 21, 26, 33, 35, 37, 38, 39, 46, 49, 54, 65, 71, 74, 77, 79, 82, 83, 88, 92, 93, 94, 97, 104, 108, 114, 115, 117, 122, 123, 127, 128, 129, 134, 137, 141, 142, 144, 147, 150, 154, 160, 163, 166, 169, 172, 173, 177, 180, 183, 184, 188, 198, 203, 208, 210, 214, 218, 220, 223, 224, 233, 236, 241, 243, 253, 256, 257, 262, 263 };
	//printf("%d\n", sizeof(a) / sizeof(a[0]));
	printf("%d\n",search(a,sizeof(a)/sizeof(a[0]),208));
	return 0;
}