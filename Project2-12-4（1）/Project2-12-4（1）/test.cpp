#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int exchangeBits(int num)
{
	int a = 1;
	while (a <= num)
	{
		//如果奇数位和偶数位相同，不做处理,a左移两位，指向下一个奇数位
		if (((num&a)==a && (num&(a<<1))==(a<<1))||((num&a)==(num&(a<<1))))
			a = a << 2;
		//如果奇数位是1，给这个数加上a
		else if ((num&a) == a)
		{
			num += a;
			a = a << 2;
		}
		else
		{
			num -= a;
			a = a << 2;
		}
	}
	return num;
	
}
int main()
{
	printf("%d", exchangeBits(571603718));
	return 0;
}