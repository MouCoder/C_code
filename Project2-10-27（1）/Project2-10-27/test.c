#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
/**链栈实现括号匹配问题
*【问题描述】
*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
*有效字符串需满足：
*	左括号必须用相同类型的右括号闭合。
*	左括号必须以正确的顺序闭合。
*	注意空字符串可被认为是有效字符串。
*示例 1:
*	输入: "()"
*	输出: true
*示例 2:
*	输入: "()[]{}"
*	输出: true
*示例 3:
*	输入: "(]"
*	输出: false
*示例 4:
*	输入: "([)]"
*	输出: false
*示例 5:
*	输入: "{[]}"
*	输出: true
*/

#include<stdbool.h>
#include<malloc.h>
char ju(char ch)
{
	if (ch == '[')
		return ']';
	else if (ch == '{')
		return '}';
	else
		return ')';
}
typedef struct linkStack
{
	char data;
	struct linkStackNode* next;
}linkStackNode;
bool judge(char* s)
{
	linkStackNode* str = NULL;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			linkStackNode* temp;

			temp = (linkStackNode*)malloc(sizeof(linkStackNode));
			temp->data = *s;
			temp->next = str;
			str = temp;
			s++;
			printf("%c入栈成功\n", temp->data);
		}
		else
		{
			if (str == NULL)
			{
				printf("多余的右括号\n");
				return false;
			}
			else
			{
				if (ju(str->data) == *s)
				{
					printf("%c出栈成功\n", str->data);
					str = str->next;
				}
				else
				{
					printf("不匹配的右括号\n");
					return false;
				}
			}
			s++;
		}
	}
	if (str == NULL)
	{
		printf("匹配成功\n");
		return true;
	}
	else
	{
		printf("多余的左括号\n");
		return false;
	}
}
int main()
{
	printf("%d\n", judge("{[()}"));
	return 0;
}