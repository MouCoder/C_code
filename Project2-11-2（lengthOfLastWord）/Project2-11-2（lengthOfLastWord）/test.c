#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int lengthOfLastWorld(char* s)
{
	/*
	*���������
	*1.�մ���"" return 0
	*2.ֻ��һ�����ʣ�return sizeof(s);
		a.���һ�����ǿո�(ת�������һ�����ʲ��ǿո��)
		b.���һ�������ַ��ǿո�
	*3.��������Ҵ������һ������:return size;
	*/
	char* end = s + strlen(s) - 1; 
	char* start = s;
	/*condition 1 
	*��Ϊs���ַ��������Բ���ֱ�ӱȽϣ�������ÿ⺯�����бȽ�
	*strcmp��������������ַ�����ȷ���0 Ŀ�괮����Դ������-1 ���򷵻�1
	*/
	if (strcmp(s, "") == 0 )
		return 0;
	/*���ַ���ĩβΪ�ո���ַ�ɾ��,������һ��ָ��ʼ��ָ���ַ���s�����һ���ǿո��ַ�*/
	while (*end == ' ' && end != start)
	{
		end--;
	}
	/*condition 2*/
	while (s != end)
	{
		if (*s == ' ')
			break;
		s++;
	}
	if (s == end && *start != ' ')
		return (end - start + 1);
	else if (s==end && *start == ' ')
		return 0;
	else
	{
		s = end;
		while (*s != ' ')
			s--;
	}
	return (end - s);

}
int main()
{
	printf("%d\n",lengthOfLastWorld("a"));
	return 0;
}