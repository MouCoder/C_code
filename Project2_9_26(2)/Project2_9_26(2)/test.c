#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char a = -1;
	//-1�����Ʊ�ʾΪ��10000001
	//���룺11111111
	//����������11111111 11111111 11111111 11111111
	//ת��Ϊԭ�룺
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}