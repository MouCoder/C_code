#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//leetcode--²ÂÊı×ÖÓÎÏ·
int guessNumber(int n){
	long long start, end, mid;
	start = 1;
	end = n;
	mid = (start + end) / 2;
	while (guess(mid))
	{
		if (guess(mid) == -1)
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