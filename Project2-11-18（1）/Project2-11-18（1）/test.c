#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//注意这里子串的定义和我们经常使用的子串的定义不同
	//不知道要输入的字符的个数，因此只能根据最大值进行定义
	char str[8000];
	scanf("%s", str);
	//注意：如果循环中使用str数组名，则无法进行str++操作，因此需要定义一个指针
	char* p = str;
	//找到H判断H前边有几个C，找到N判断前边有几个CHN，最终CHN的总个数就是子串个数
	long long c = 0, ch = 0, chn = 0;
	while (*p)
	{
		if (*p == 'C')
		{
			c++;
		}
		else if (*p == 'H')
		{
			ch += c;
		}
		else if (*p == 'N')
		{
			chn += ch;
		}
		p++;
	}
	printf("%lld", chn);
	return 0;
}