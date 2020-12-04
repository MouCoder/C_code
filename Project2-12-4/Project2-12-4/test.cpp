#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char findTheDifference(char * s, char * t)
{
	//将两个字符串中的字符进行异或运算，相同的字符会被异或成ASCII为0的字符，最终只剩下添加的一个字符
	char ret = '\0';//它的ASCII为0，所有数与他异或结果都为数本身
	while (*t)
	{
		ret ^= *t;
		t++;
	}
	while (*s)
	{
		ret ^= *s;
		s++;
	}
	return ret;
}
int main()
{
	char* a = "abcd";
	char* b = "abcde";
	printf("%d\n",findTheDifference(a,b));
	return 0;
}