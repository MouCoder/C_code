#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//int judge_string(char* p1,char* p2)
//{
//	//printf("%c,%c\n", *p1, *p2);
//	while (*p2)
//	{
//		if (*p1 == *p2)
//		{
//			p1++;
//			p2++;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
int judge_stringSpin(char* p1,char*p2)
{
	char* tmp = p1;
	//��������ַ����ĳ��Ȳ���ͬ����ô�������ַ����ز�����ΪΪ��ת֮����ַ���
	if (strlen(p1) == strlen(p2))
	{
		while (*p2)
		{
			if (*p1 == *p2)
			{
				if (*(p2+1))
				{
					p1++;
					p2++;
				}
				else
				{
					p2 -= (strlen(tmp) - 1);
					p1++;
					while (*p1)
					{
						if (*p1 == *p2)
						{
							if (*(p1 + 1))
							{
								p1++;
								p2++;
							}
							else
							{
								return 1;
							}
						}
						else
						{
							return 0;
						}
					}
				}
			}
			else
			{
				if (p1 == tmp)
				{
					p2++;
				}
				else
				{
					p1 = tmp;
				}
			}
		}
	}
	return 0;
}
int main()
{
	/*дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
	���磺����s1 = AABCD��s2 = BCDAA������1
	����s1 = abcd��s2 = ACBD������0.
	AABCD����һ���ַ��õ�ABCDA
	AABCD���������ַ��õ�BCDAA
	AABCD����һ���ַ��õ�DAABC*/
	//����һ�������20���ַ����ַ���
	char str1[20] = "abcdefgh";
	char str2[20];
	printf("������һ��С��20���ַ����ַ���:>");
	scanf("%s", str2);
	//�ж��ַ���str2�Ƿ�Ϊstr1����ת��
	printf("%d\n",judge_stringSpin(str1,str2));

	return 0;
}