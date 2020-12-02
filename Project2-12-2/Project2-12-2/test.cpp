#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给定一个有序数组，找数组中最接近给定值sum的两个数
int* search(int *num,int numSize,int sum)
{
	int s = 0, e = numSize - 1;
	/*此题目中，数组元素有序，所以a,b两个数可以分别从开始和结尾处开始搜
	，根据首尾元素的和是否大于sum,决定搜索的移动，整个数组被搜索一遍，
	就可以得到结果，所以最好时间复杂度为n*/
	int ret[2];
	while (1)
	{
		if (num[s] + num[e] > sum)
			e--;
		else if (num[s] + num[e] < sum && num[s + 1] + num[e] > sum)
		{
			ret[0] = s;
			ret[1] = e;
			return ret;
		}
		else
		{
			s++;
		}
	}
	return ret;
}
int main()
{
	int num[] = {1,2,5,9,10,16,25};
	int sum = 18;
	search(num, 7, sum);
	return 0;
}