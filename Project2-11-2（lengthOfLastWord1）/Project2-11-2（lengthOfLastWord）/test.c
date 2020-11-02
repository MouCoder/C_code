#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int lengthOfLastWorld(char* s)
{
	/*
	*分情况讨论
	*1.空串："" return 0
	*2.只有一个单词：return sizeof(s);
		a.最后一个不是空格(转换成最后一个单词不是空格的)
		b.最后一个或多个字符是空格
	*3.多个单词且存在最后一个单词:return size;
	*/
	char* end = s + strlen(s) - 1; 
	char* start = s;
	/*condition 1 
	*因为s是字符串，所以不能直接比较，这里调用库函数进行比较
	*strcmp函数，如果两个字符串相等返回0 目标串大于源串返回-1 否则返回1
	*/
	if (strcmp(s, "") == 0 )
		return 0;
	/*将字符串末尾为空格的字符删掉,即定义一个指针始终指向字符串s的最后一个非空格字符*/
	while (*end == ' ' && end != start)
	{
		end--;
	}
	/*condition 2*/
	while (s != end)
	{
		if (*s == ' ')
			break;
		s++;
	}
	if (s == end && *start != ' ')
		return (end - start + 1);
	else if (s==end && *start == ' ')
		return 0;
	else
	{
		s = end;
		while (*s != ' ')
			s--;
	}
	return (end - s);

}
int main()
{
	printf("%d\n",lengthOfLastWorld("a"));
	return 0;
}