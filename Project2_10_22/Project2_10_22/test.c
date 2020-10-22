#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strlen(const char * str)
{
	int ret = 0;
	while (*str)
	{
		str++;
		ret++;
	}
	return ret;
}
int my_strcmp(const char * str1, const char * str2)
{
	//如果str1>str2返回1，等于返回0，小于返回-1
	assert(str1);
	assert(str2);
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 > *str2)
			return 1;
		else
			return -1;
	}
	if (*str1)
		return -1;
	else if (*str2)
		return 1;
	else
		return 0;
}

char* my_strcpy1(char * destination, const char * source)
{
	assert(destination);
	assert(source);
	/*while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination-strlen(source);*/

	//改进
	//注：后置++的优先级高于*的优先级
	char* ret = destination;
	while (*destination++ = *source++);
	*destination = '\0';
	//返回目标字符串的首地址
	return ret;
	
}

int main()
{
	/*char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	my_strcpy1(str2, str1);
	my_strcpy1(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);*/

	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("The sentence entered is %u characters long.\n", (unsigned)my_strlen(szInput));
	return 0;
}