#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool detectCapitalUse(char * word)
{
	if (strlen(word) == 1)
		return true;
	//如果单词的第一个字母是小写字母，则后边所有字母都必须是小写
	if (*word >= 'a' && *word <= 'z')
	{
		while (*word)
		{
			if (*word >= 'a' && *word <= 'z')
			{
				word++;
			}
			else
			{
				return false;
			}
		}
	}
	//单词的第一个单词是大写，要么后边所有字母都是小写要么后边所有字母都是大写，才可以
	else
	{
		word++;
		if (*word >= 'A' && *word <= 'Z')
		{
			while (*word)
			{
				if (*word >= 'A' && *word <= 'Z')
				{
					word++;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			while (*word)
			{
				if (*word >= 'a' && *word <= 'z')
				{
					word++;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	printf("%d\n",detectCapitalUse("a"));
	return 0;
}