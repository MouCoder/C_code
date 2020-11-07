#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isPalindrome(char * s)
{
	/*��֤���Ĵ�*/
	//��start��end�ֱ�ָ���ַ���s��ͷ��β�����α����ַ������Ƚ�
	char* start = s;
	char* end = s + (strlen(s) - 1);
	//��strlen(s)%2 == 0ʱ���ж�����Ӧ��Ϊstart + 1 = end;
	//��strlen(s)%2 != 0ʱ���ж�����Ӧ��Ϊstart = end;
	while ((start + 1 <= end) || (start <= end))
	{
		//�ж�start��end�Ƿ�Ϊ���֡��ַ��е�һ�֣����start��end���ǣ��ͼ����ж������Ƿ����
		//���start���ǡ���start++�����end����end--,�����������start++��end--
		if ((*start >= '0' && *start <= '9') || (*start >= 'A' && *start <= 'Z') || (*start >= 'a' && *start <= 'z'))
		{
			if ((*end >= '0' && *end <= '9') || (*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z'))
			{
				if (*start == *end)
				{
					start++;
					end--;
				}
				else if (((*start >= 'A' && *start <= 'Z') || (*start >= 'a' && *start <= 'z')) && ((*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z')))
				{
					if ((*start - *end == 32) || (*end - *start == 32))
					{
						start++;
						end--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				end--;
			}
		}
		else
		{
			start++;
		}
	}
	return true;
}
int main()
{
	printf("%d\n", isPalindrome("0P"));
	return 0;
}