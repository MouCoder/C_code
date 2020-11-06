#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int mySqrt(int x)
{
	//Çî¾Ù·¨
	if (x == 1)
		return 1;
	int i = 1;
	for (; i <= x / 2 && i*i <= x; i++)
	{
		if (i == 46340 || i*i == x)
			return i;
	}
	return i - 1;
}
int main()
{
	printf("%d\n", mySqrt(2147483647));
	return 0;
}