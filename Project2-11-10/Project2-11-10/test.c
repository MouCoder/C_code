#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int firstUniqChar(char * s)
{
	//1.�մ�(return -1)2.�����ַ��Ĵ�(return 0)3.������ͬ�ַ��Ĵ�(return -1)
	char* str = s;
	char* end = s;
	//ÿһ���ַ������ַ����е����������ַ����бȽϣ������������ͬ�ַ���ֱ�ӷ��ظ��ַ����±꣬��������ж�
	while (*str)
	{
		//����жϵ���ǰ�ַ�����λ�ã�ֱ�������ж���һ��λ��
		if (end == str)
		{
			end++;
		}
		//�����������ַ�����������һ���ַ���ͷ��ʼ�����ж�
		else if (*end == *str)
		{
			end = s;
			str++;
		}
		else if (*end == '\0')
		{
			return str - s;
		}
		else
		{
			end++;
		}
	}
	return -1;
}
int main()
{
	printf("%d\n",firstUniqChar(""));
	return 0;
}