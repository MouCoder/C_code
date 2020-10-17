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
	//如果两个字符串的长度不相同，那么这两个字符串必不可能为为旋转之后的字符串
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
	/*写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
	例如：给定s1 = AABCD和s2 = BCDAA，返回1
	给定s1 = abcd和s2 = ACBD，返回0.
	AABCD左旋一个字符得到ABCDA
	AABCD左旋两个字符得到BCDAA
	AABCD右旋一个字符得到DAABC*/
	//定义一个最多有20个字符的字符串
	char str1[20] = "abcdefgh";
	char str2[20];
	printf("请输入一个小于20个字符的字符串:>");
	scanf("%s", str2);
	//判断字符串str2是否为str1的旋转串
	printf("%d\n",judge_stringSpin(str1,str2));

	return 0;
}