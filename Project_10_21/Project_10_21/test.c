#define _CRT_SECURE_NO_WARNINGS 1

/*
*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
*示例 1:
*	输入: 123
*	输出: 321
*示例 2:
*	输入: -123
*	输出: -321
*示例 3:
*	输入: 120
*	输出: 21
*【注意】:假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 
*		[−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
		[-2147483648，2147483647]
*/

int reverse(int x)
{
	int result = 0;
	while (x)
	{
		//214748364 = int_max /10
		//-214748364 = int_min/10
		if (result > 214748364 || (result == 214748364 && x % 10 > 7))
		{
			return 0;
		}
		else if (result < -214748364 || (result == -214748364 && x % 10 < -8))
		{
			return 0;
		}
		else
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
	}
	return result;
}
int main()
{
	int x = 123;
	printf("%d\n", reverse(x));
	return 0;
}