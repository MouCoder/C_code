#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char findTheDifference(char * s, char * t)
{
	//�������ַ����е��ַ�����������㣬��ͬ���ַ��ᱻ����ASCIIΪ0���ַ�������ֻʣ����ӵ�һ���ַ�
	char ret = '\0';//����ASCIIΪ0�������������������Ϊ������
	while (*t)
	{
		ret ^= *t;
		t++;
	}
	while (*s)
	{
		ret ^= *s;
		s++;
	}
	return ret;
}
int main()
{
	char* a = "abcd";
	char* b = "abcde";
	printf("%d\n",findTheDifference(a,b));
	return 0;
}