#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool checkRecord(char * s)
{
	int countA = 0;
	while (*s)
	{
		if (*s == 'A')
		{
			countA++;
		}
		else if (*s == 'L')
		{
			if (*(s + 1) == 'L' && *(s + 2) == 'L')
			{
				return false;
			}
		}
		if (countA > 1)
			return false;
		else
			s++;
	}
	return true;
}
int main()
{
	printf("%d\n", checkRecord("PPALLL"));
	return 0;
}