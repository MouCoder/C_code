#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
char * longestPalindrome(char * s)
{
	//������Ӵ�---��̬�滮
	int LengthOfSource = strlen(s);
	//ָ��bp����LengthOfSource*LengthOfSource������Ϊbool�Ŀռ䣬���ڱ�ʾһ����ά���飬�����(i*LengthOfSource+j)�ͱ�ʾ��ά����ĵ�i,j��Ԫ��
	bool* bp = (bool*)malloc(sizeof(bool)*((int)pow(strlen(s),2)));
	int m = 0;
	for (m = 0; m < (int)pow(strlen(s), 2); m++)
		bp[m] = false;
	char* ans =NULL;
	ans = (char*)malloc(sizeof(char)*LengthOfSource);
	//i,j�ֱ��ʾ�Ӵ��Ŀ�ʼ�ͽ�βλ�ã�l��ʾ�Ӵ��� ����
	int i, j, l;
	//�Ӵ�����С����Ӧ��Ϊ1����󳤶�Ӧ��ΪLengthOfSource
	for (l = 0; l < LengthOfSource; l++)
	{
		for (i = 0; i + l < LengthOfSource; i++)
		{
			//����ַ����ĳ��ȴ���0��j���ڵ�λ��Ϊ��i��ʼ����Ϊl���ַ��������һ��λ�õ���һ��λ��
			j = i + l;
			{
				if (l == 0)
				{
					bp[i*LengthOfSource + j] = true;
				}
				else if (l == 1)
				{
					bp[i*LengthOfSource + j] = (s[i] == s[j]) ? true : false;
				}
				else
				{
					bp[i*LengthOfSource + j] = (s[i] == s[j] && bp[(i + 1)*LengthOfSource + j - 1]);
				}
				if (bp[i*LengthOfSource + j] && l + 1 > (int)strlen(ans)) 
				{
					strncat(ans,s+i, l+1);
				}
			}
		}
	}
	return ans;
}
int main()
{
	printf("%s\n", longestPalindrome("babad"));
	return 0;
}