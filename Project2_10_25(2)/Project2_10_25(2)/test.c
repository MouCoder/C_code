#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
/*
*编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
*示例 1:
*	输入: ["flower","flow","flight"]
*	输出: "fl"
*示例 2:
*	输入: ["dog","racecar","car"]
*	输出: ""
*	解释: 输入不存在公共前缀。
*说明:所有输入只包含小写字母 a-z 
*/
char* longestCommonPrefix(char** strs, int strsSize)
{
	int i, j;
	if (strsSize == 0)
	{
		return "";
	}
	else if (strsSize == 1)
	{
		return strs[0];
	}
	else
	{
		for (i = 0; i < strlen(strs[0]); i++)
		for (j = 0; j < strsSize - 1; j++)
		{
			if (*(strs[j] + i) != *(strs[j + 1] + i))
			{
				*(strs[0] + i) = '\0';
				return strs[0];
			}
		}
	}
	return strs[0];
}
int main()
{
	char* str[] = { "flower", "flow", "flight" };
	printf("%s\n", longestCommonPrefix(str, 3));
	return 0;
}