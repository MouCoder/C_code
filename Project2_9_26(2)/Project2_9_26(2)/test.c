#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char a = -1;
	//-1二进制表示为：10000001
	//补码：11111111
	//整形提升：11111111 11111111 11111111 11111111
	//转化为原码：
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}