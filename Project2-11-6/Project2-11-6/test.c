#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char * s)
{
	if (strlen(s) == 0)
		return 0;
	//ָ��endʼ��ָ���ַ���s�����һ���ǿո��ַ�
	//ָ��startָ���ַ��������һ�����ʵĵ�һ����ĸ��λ��
	char* end= s + strlen(s) - 1;
	char* start = end;
	while (end != s && *end == ' ')
		end--;
	if (*end == ' ')
		return 0;
	start = end;
	while (start != s && *(start - 1) != ' ')
		start--;
	return end - start + 1;
	
}
int main()
{
	char* s = "     ";
	printf("%d\n", lengthOfLastWord(s));
	return 0;
}