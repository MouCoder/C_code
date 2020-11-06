#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char * s)
{
	if (strlen(s) == 0)
		return 0;
	//指针end始终指向字符串s的最后一个非空格字符
	//指针start指向字符串中最后一个单词的第一个字母的位置
	char* end= s + strlen(s) - 1;
	char* start = end;
	while (end != s && *end == ' ')
		end--;
	if (*end == ' ')
		return 0;
	start = end;
	while (start != s && *(start - 1) != ' ')
		start--;
	return end - start + 1;
	
}
int main()
{
	char* s = "     ";
	printf("%d\n", lengthOfLastWord(s));
	return 0;
}