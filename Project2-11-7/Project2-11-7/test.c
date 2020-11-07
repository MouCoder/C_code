#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isPalindrome(char * s)
{
	/*验证回文串*/
	//让start和end分别指向字符串s的头和尾，依次遍历字符串并比较
	char* start = s;
	char* end = s + (strlen(s) - 1);
	//当strlen(s)%2 == 0时，判断条件应该为start + 1 = end;
	//当strlen(s)%2 != 0时，判断条件应该为start = end;
	while ((start + 1 <= end) || (start <= end))
	{
		//判断start和end是否为数字、字符中的一种，如果start和end都是，就继续判断两个是否相等
		//如果start不是。则start++，如果end不是end--,如果都不是则start++，end--
		if ((*start >= '0' && *start <= '9') || (*start >= 'A' && *start <= 'Z') || (*start >= 'a' && *start <= 'z'))
		{
			if ((*end >= '0' && *end <= '9') || (*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z'))
			{
				if (*start == *end)
				{
					start++;
					end--;
				}
				else if (((*start >= 'A' && *start <= 'Z') || (*start >= 'a' && *start <= 'z')) && ((*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z')))
				{
					if ((*start - *end == 32) || (*end - *start == 32))
					{
						start++;
						end--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				end--;
			}
		}
		else
		{
			start++;
		}
	}
	return true;
}
int main()
{
	printf("%d\n", isPalindrome("0P"));
	return 0;
}