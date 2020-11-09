#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverseString(char* s, int sSize)
{
	int i = 0;
	char tag;
	for (i = 0; i < sSize/2; i++)
	{
		tag = s[i];
		s[i] = s[sSize - i - 1];
		s[sSize - i - 1] = tag;
	}
}
int main()
{

	return 0;
}