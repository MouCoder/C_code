#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int VowelCharacter(char ch)
{
	//如果是元音字符返回1，否则返回0
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return 1;
	}
	else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		return 1;
	}
	return 0;
}
char * reverseVowels(char * s)
{
	if (strlen(s) == 0)
		return s;
	//i,j分别为字符串s的第一个字符的下标和最后一个字符的下标
	int i=0, j=strlen(s);
	char* ret = (char*)malloc(strlen(s)+1);
	while (i < j)
	{
		//如果两个都是元音字符，则两个字符交换
		if (VowelCharacter(s[i]) && VowelCharacter(s[j]))
		{
			ret[i] = s[j];
			ret[j] = s[i];
			i++;
			j--;
		}
		//如果前边的字符是元音字符，将后边的字符放在靠后的位置
		else if (VowelCharacter(s[i]))
		{
			ret[j] = s[j];
			j--;
		}
		//如果后边的字符是元音字符，将前边的字符放在指定的位置
		else if (VowelCharacter(s[j]))
		{
			ret[i] = s[i];
			i++;
		}
		//如果两个都不是元音字符，将前边的字符放在靠前的位置，后边字符放在靠后的位置
		else
		{
			ret[i] = s[i];
			i++;
			ret[j] = s[j];
			j--;
		}
	}
	//如果i和j相等，说明此时i的位置为元音字符，将i放在第i个位置上
	if (i == j)
	{
		ret[i] = s[i];
	}
	return ret;
}
int main()
{
	printf("%s\n",reverseVowels("a."));
	return 0;
}