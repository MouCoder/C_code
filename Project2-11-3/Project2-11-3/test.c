#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*题目：无重复字符的最长子串
*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*示例 1:
*	输入: "abcabcbb"
*	输出: 3
*	解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*示例 2:
*	输入: "bbbbb"
*	输出: 1
*	解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*示例 3:
*	输入: "pwwkew"
*	输出: 3
*	解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
*请注意，你的答案必须是子串的长度，"pwke" 是一个子序列，不是子串。
*/
int lengthOfLongestSubstring(char * s)
{
	/*题目分析
	*POINT->1.无重复字符\2.最长子串\3.返回长度
	*1.空串->return 0;
	*2.空格串->
	*3.
	*/
	int length = strlen(s);
	int MaxLength = 0;
	int i;
	if (length==0)
		return 0;
	else
	{

		//只有一个字符
		if (length == 1)
			return 1;
		else
		{
			char* p = s;
			char* q = s + 1;
			//指针p和q分别指向子串的头和尾，当q指针指向s的最后一个元素时有两种可能
			//1.*q与当前子串中的字符没有重复（p位置之后的所有子串都不可能比这个子串长，后边的也就都不需要判断了）
			//2.*q与当前子串中的字符有重复（p之后的所有子串最多与这个子串一样长，后边的也就都不需要判断了）
			//当指针p指向最后一个元素的时候，就没有继续判断的必要了，此时要么已有最长无重复子串的场赌博，要么最长长度为1
			while ((p != s + length - 1) && (q != s + length))
			{
				//判断当前q所指的字符是否与该串中的字符重复，因此应该从p位置开始判断，到q-1的位置结束
				//s始终指向字符串的第一个字符，所以无论是p-s还是q-s都表示的是当前指针在字符串s中的位置
				for (i = p - s; i < q - s;i++)
				if (*q == s[i])
				{
					//将较大的长度进行保存
					MaxLength = MaxLength >= (q - p) ? MaxLength : (q - p);
					p++;
					q = p + 1;
					break;
				}
				if (i == q - s)
					q++;
			}
			//如果是因为q到达最后一个字符而结束循环，应该将最后一结果和之前的较大值保存
			if (q == s+length)
				MaxLength = MaxLength >= (q - p) ? MaxLength : (q - p);
		}
	}
	return MaxLength;
}
int main()
{
	char* p = "ab";
	printf("%d\n",lengthOfLongestSubstring(p));
	return 0;
}