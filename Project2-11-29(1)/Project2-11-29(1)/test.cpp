#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
bool isSubsequence(char * s, char * t)
{
	if (*s == '\0')
		return true;
	else if (*t == '\0')
		return false;
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		while (*t)
		{
			if (s[i] == *t)
			{
				t++;
				break;
			}
			t++;
		}
		if (*t == '\0' && s[i] != *(t - 1))
			return false;
		else if (*t == '\0' && i != strlen(s) - 1)
			return false;
	}
	return true;
}
int main()
{
	char* s = "aaaaaa";
	char* t = "bbaaaa";
	printf("%d\n",isSubsequence(s,t));
	return 0;
}