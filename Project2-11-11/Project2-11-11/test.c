#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int maxProfit(int* prices, int pricesSize)
{
	int max = 0;
	int* start = prices;
	int* end = prices + pricesSize - 1;
	while (prices < end)
	{
		while (prices != end)
		{
			if (*prices < *end)
			{
				max = max>(*end - *prices) ? max : (*end - *prices);
			}
			end--;
		}
		end = start + pricesSize - 1;
		prices++;
	}
	return max;
}
int main()
{
	int nums[] = {7, 1, 5, 3, 6, 4};
	printf("%d\n",maxProfit(nums,6));
	return 0;
}