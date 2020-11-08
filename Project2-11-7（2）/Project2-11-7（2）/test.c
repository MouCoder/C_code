#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
char * longestPalindrome(char * s)
{
	//最长回文子串---动态规划
	int LengthOfSource = strlen(s);
	//指针bp分配LengthOfSource*LengthOfSource个类型为bool的空间，用于表示一个二维数组，例如第(i*LengthOfSource+j)就表示二维数组的第i,j个元素
	bool* bp = (bool*)malloc(sizeof(bool)*((int)pow(strlen(s),2)));
	int m = 0;
	for (m = 0; m < (int)pow(strlen(s), 2); m++)
		bp[m] = false;
	char* ans =NULL;
	ans = (char*)malloc(sizeof(char)*LengthOfSource);
	//i,j分别表示子串的开始和结尾位置，l表示子串的 长度
	int i, j, l;
	//子串的最小长度应该为1，最大长度应该为LengthOfSource
	for (l = 0; l < LengthOfSource; l++)
	{
		for (i = 0; i + l < LengthOfSource; i++)
		{
			//如果字符串的长度大于0，j所在的位置为以i开始长度为l的字符串的最后一个位置的下一个位置
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