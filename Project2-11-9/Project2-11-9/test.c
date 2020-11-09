#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int myAtoi(char * s)
{
	//先让s指向字符串的第一个非空格字符
	while (*s == ' ' && *(++s));/*后置++的优先级高于*，但是后置++是先使用在++*/
	//如果第一个非空格字符是数字或者‘-’、‘+’时继续运算，否则直接返回0
	if (*s == '-' || *s == '+' || (*s >= '0' && *s <= '9'))
	{
		double ret = 0;
		int minus = 1;
		if (*s == '-')
		{
			minus = -1;
			s++;
		}
		else if (*s == '+')
		{
			s++;
		}
		while ((*s >= '0' && *s <= '9') && *s)
		{
			ret = ret * 10 + (int)(*s - '0');
			s++;
		}
		if (minus == 1)
			return (int)ret == ret ? (int)ret : 2147483647;
		return (int)ret == ret?minus*(int)ret:(int)ret;
	}
	return 0;
}
int main()
{
	printf("%d\n", myAtoi("-91283472332"));
	return 0;
}