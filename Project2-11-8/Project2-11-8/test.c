#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strlen1(const char* str)
{
	//count记录字符串的长度
	int count = 0;
	while (*str++)
		count++;
	return count;
}
int my_strlen(const char* str)
{
	const char* ret = str;
	while (*ret)
	{
		ret++;
	}
	return ret - str;
}


char* my_strcpy(char * destination, const char * source)
{
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return destination;
}
char* my_strcat(char * destination, const char * source)
{
	assert(destination != NULL);
	assert(source != NULL);
	char* ret = destination;
	while (*destination)
	{
		destination++;
	}
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return ret;
}
int my_strcmp(const char * str1, const char * str2)
{
	assert(str1);
	assert(str2);
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			if (*str1 > *str2)
				return 1;
			else
				return -1;
		}
	}
	if (*str1)
	{
		return 1;
	}
	else
	{
		if (*str1 == *str2)
			return 0;
		else
			return -1;
	}
}
char* my_strncpy(char * destination, const char * source, int num)
{
	while (num)
	{
		*destination = *source;
		destination++;
		source++;
		num--;
	}
	*destination = '\0';
	return destination;
}
char * my_strncat(char * destination, const char * source, int num)
{
	char* ret = destination;
	while (*destination)
	{
		destination++;
	}
	while (num)
	{
		*destination = *source;
		destination++;
		source++;
		num--;
	}
	*destination = '\0';
	return ret;
}
void * my_memcpy(void * destination, const void * source, int num)
{
	char* dst = (char*)destination;
	char* src = (char*)source;
	while (num)
	{
		*dst = *src;
		dst++;
		src++;
		num--;
	}
	*dst = '\0';
	return destination;
}

struct {
	char name[40];
	int age;
} person, person_copy;
//int main()
//{
//	//printf("%d\n",my_strlen("abc"));
//
//	//char str1[] = "Sample string";
//	//char str2[40];
//	//char str3[40];
//	//my_strcpy(str2, str1);
//	//my_strcpy(str3, "copy successful");
//	///*str1: Sample string
//	//str2 : Sample string
//	//str3 : copy successful*/
//	//printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
//
//	/*char str[80];
//	strcpy(str, "these ");
//	my_strcat(str, "strings ");
//	my_strcat(str, "are ");
//	my_strcat(str, "concatenated.");
//	puts(str);*/
//
//	/*char key[] = "apple";
//	char buffer[80];
//	do {
//		printf("Guess my favorite fruit? ");
//		fflush(stdout);
//		scanf("%79s", buffer);
//	} while (my_strcmp(key, buffer) != 0);
//	puts("Correct answer!");*/
//
//	//char str1[] = "To be or not to be";
//	//char str2[40];
//	//char str3[40];
//	///* copy to sized buffer (overflow safe): */
//	//my_strncpy(str2, str1, sizeof(str2)-1);
//	// /*partial copy (only 5 chars): */
//	//my_strncpy(str3, str2, 5);
//	////str3[5] = '\0';   /* null character manually added */
//	//puts(str1);
//	//puts(str2);
//	//puts(str3);
//
//	/*char str1[20];
//	char str2[20];
//	my_strcpy(str1, "To be ");
//	my_strcpy(str2, "or not to be");
//	my_strncat(str1, str2, 6);
//	puts(str1);*/
//
//	//char myname[] = "Pierre de Fermat";
//	///* using memcpy to copy string: */
//	//my_memcpy(person.name, myname, strlen(myname) + 1);
//	//person.age = 46;
//	///* using memcpy to copy structure: */
//	//my_memcpy(&person_copy, &person, sizeof(person));
//	//printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//
//
//	return 0;
//}

