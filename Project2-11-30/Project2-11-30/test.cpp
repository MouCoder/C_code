#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	//先合并，在排序，利用冒泡排序
	int i = m, j = 0;
	int mid;
	while (j != n)
	{
		nums1[m] = nums2[j];
		m++;
		j++;
	}
	for (i = 0; i < nums1Size - 1; i++)
	for (j = i + 1; j<nums1Size; j++)
	{
		if (nums1[i] > nums1[j])
		{
			mid = nums1[i];
			nums1[i] = nums1[j];
			nums1[j] = mid;
		}
	}
}