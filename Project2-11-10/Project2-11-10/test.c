#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int firstUniqChar(char * s)
{
	//1.空串(return -1)2.单个字符的串(return 0)3.两个相同字符的串(return -1)
	char* str = s;
	char* end = s;
	//每一个字符都跟字符串中的其他所有字符进行比较，如果不存在相同字符，直接返回该字符的下标，否则继续判断
	while (*str)
	{
		//如果判断到当前字符所在位置，直接跳过判断下一个位置
		if (end == str)
		{
			end++;
		}
		//如果遇到相等字符，重新用下一个字符从头开始进行判断
		else if (*end == *str)
		{
			end = s;
			str++;
		}
		else if (*end == '\0')
		{
			return str - s;
		}
		else
		{
			end++;
		}
	}
	return -1;
}
int main()
{
	printf("%d\n",firstUniqChar(""));
	return 0;
}