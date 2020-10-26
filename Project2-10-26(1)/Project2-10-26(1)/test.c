#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//将单个罗马数字转int型
int oneRomanToInt(char roman)
{
	switch (roman)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;
	}
}
int romanToInt(char * s)
{
	//注意
	//1.搞清楚罗马数字转int的规则，总结一句话为如果当前位数字小于下一位，则做减法否则做加法
	//即，IV=-1+5=4，VI=5+1=6
	int ret = 0;
	while (*s)
	{
		if (oneRomanToInt(*s) < oneRomanToInt(*(s + 1)))
		{
			ret -= oneRomanToInt(*s);
			s++;
		}
		else
		{
			ret += oneRomanToInt(*s);
			s++;
		}
	}
	return ret;
}
int main()
{
	char s[] = "CMXCIX";
	printf("%d\n", romanToInt(s));
	return 0;
}