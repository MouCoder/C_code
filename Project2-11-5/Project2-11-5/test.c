#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * addBinary(char * a, char * b)
{
	/*二进制求和
	*给你两个二进制字符串，返回它们的和（用二进制表示）。输入为非空字符串且只包含数字 1 和 0。
	*/
	char* ret = NULL;
	//指针pa pb分别指向a b的最后一个字符，用于从后向前遍历a b
	char* pa = a + strlen(a) - 1;
	char* pb = b + strlen(b) - 1;
	//pa-a/pb-b表示的是字符串a/b的长度减一。这一步的目的是给ret分配a b中较长的字符串的大小加2个字节的空间，利用pa-a/pb-b的目的是减小时间复杂度
	ret = (char*)malloc((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3));
	//((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3))表示字符串ret的长度，让pr指向ret的最后一个字节，并将该字节赋值为结束标志符
	char* pr = ret + ((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3)) - 1;
	*pr = '\0';
	pr--;
	//将pr全部初始化为‘0’
	while (pr >= ret)
	{
		*pr = '0';
		pr--;
	}
	pr = ret + strlen(ret) - 1;//pr返回ret的最后一个字符
	while (pa >= a && pb >= b)
	{
		switch (*pa - '0' + *pb - '0' + *pr - '0')
		{
		case 0:
			*pr = '0';
			break;
		case 1:
			*pr = '1';
			break;
		case 2:
			*pr = '0';
			*(pr - 1) = '1';
			break;
		case 3:
			*pr = '1';
			*(pr - 1) = '1';
			break;
		}
		pr--;
		pa--;
		pb--;
	}
	//a完了，b没完
	if (pa < a && pb >= b)
	{
		while (pb >= b)
		{
			if (*pr - '0' + *pb - '0' == 2)
			{
				*pr = '0';
				*(pr - 1) = '1';
				pr--;
				pb--;
			}
			else
			{
				*pr = *pb>*pr?*pb:*pr;
				pr--;
				pb--;
			}
		}
	}
	else if (pb < b && pa >= a)
	{
		while (pa >= a)
		{
			if (*pr - '0' + *pa - '0' == 2)
			{
				*pr = '0';
				*(pr - 1) = '1';
				pr--;
				pa--;
			}
			else
			{
				*pr = *pa>*pr ? *pa : *pr;
				pr--;
				pa--;
			}
		}
	}
	if (*ret == '0')
		return ret + 1;
	else
		return ret;
}
int main()
{
	char * a = "1";
	char* b = "111";
	char* ret = addBinary(a,b);
	printf("%s\n",ret);
	return 0;
}