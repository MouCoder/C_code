#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

//C语言中没有布尔值，但是在c99要求只要引入头文件#include<stdbool.h>就可以使用布尔值
//即true=1，false=0；

bool isPalindrome(int x)
{
/**
*判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*示例 1:
*	输入 : 121
*	输出 : true
*示例 2 :
*	输入 : -121
*	输出 : false
*	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
*示例 3 :
*	输入 : 10
*	输出 : false
*	解释 : 从右向左读, 为 01 。因此它不是一个回文数。
*/
	long long ret = 0;
	int x1 = x;
	//负数一定不是回文数
	if (x < 0)
		return false;
	else if (x >= 0 && x <= 9)
		return true;
	else
	{
		while (x)
		{
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		if ((int)ret == x1)
		{
			return true;
		}
		else
			return false;
	}
}
int main()
{
	printf("%d\n", isPalindrome(1234567899));
	return 0;
}