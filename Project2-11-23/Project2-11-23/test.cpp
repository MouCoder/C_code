#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//lettcode---��һ������İ汾��
int firstBadVersion(int n) {
	//�汾��Ӧ�ô�1��ʼ��n����
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