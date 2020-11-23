#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//lettcode---第一个错误的版本号
int firstBadVersion(int n) {
	//版本号应该从1开始到n结束
	double start, end, mid;
	start = 1;
	end = n;
	mid = (start + end) / 2;
	while (!(isBadVersion(mid) && !(isBadVersion(mid - 1))))
	{
		if (isBadVersion(mid))
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}
	return mid;
}