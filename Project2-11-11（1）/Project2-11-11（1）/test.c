#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * toLowerCase(char * str)
{
	char* ret = (char*)malloc(strlen(str)+1);
	char* ret1 = ret;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*ret = (char)(*str + 32);
		}
		else
		{
			*ret = *str;
		}
		ret++;
		str++;
	}
	*ret = '\0';
	return ret1;
}
int main()
{
	printf("%s\n",toLowerCase("hehre"));
	return 0;
}