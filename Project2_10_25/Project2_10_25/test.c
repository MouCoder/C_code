#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
void * my_memcpy(void * destination, const void * source, size_t num)
{
	//Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.
	const char* src = (char*)source;
	char* dst = (char*)destination;
	while (num)
	{
		*dst = *src;
		dst++;
		src++;
		num--;
	}
	return destination;
}
char* my_strstr(char * str1, const char * str2)
{
	//Returns a pointer to the first occurrence of str2 in str1
	assert(str1);
	assert(str2);

	//record the local of str1 and str2
	char* str1_dst;
	const char* str2_src;

	while (*str1)
	{
		if (*str1 != *str2)
		{
			str1++;
		}
		else
		{
			str1_dst = str1;
			str2_src = str2;
			while (*str1++ == *str2++ && *str2);
			if (*str2 == '\0')
			{
				return str1_dst;
			}
			else
			{
				str1 = str1_dst + 1;
				str2 = str2_src;
			}
		}
	}

	return NULL;
}

char* my_strcat(char * destination, const char * source)
{
	//将源字符串拼接在目标字符串的结尾
	assert(destination);
	assert(source);
	
	//method 1
	//让指针指向目标字符串的'\0'的位置
	/*destination += strlen(destination);
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';*/

	//method 2
	destination += strlen(destination);
	while (*destination++ = *source++);
	*destination = '\0';

	return destination;
}
struct {
	char name[40];
	int age;
} person, person_copy;

int main()
{
	//strcat
	/*char str[80];
	strcpy(str, "these ");
	my_strcat(str, "strings ");
	my_strcat(str, "are ");
	my_strcat(str, "concatenated.");
	puts(str);*/

	//strstr
	/*char str[] = "This is a simple string";
	char * pch;
	pch = my_strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);*/

	//memcopy
	int num[] = { 1, 2, 3, 4, 5 };
	int num2[10];
	int i;
	my_memcpy(num2, num, 5);
	for (i = 0; i < 10;i++)
	printf("%2d", num[i]);

	return 0;
}