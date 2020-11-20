#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int VowelCharacter(char ch)
{
	//�����Ԫ���ַ�����1�����򷵻�0
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return 1;
	}
	else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		return 1;
	}
	return 0;
}
char * reverseVowels(char * s)
{
	if (strlen(s) == 0)
		return s;
	//i,j�ֱ�Ϊ�ַ���s�ĵ�һ���ַ����±�����һ���ַ����±�
	int i=0, j=strlen(s);
	char* ret = (char*)malloc(strlen(s)+1);
	while (i < j)
	{
		//�����������Ԫ���ַ����������ַ�����
		if (VowelCharacter(s[i]) && VowelCharacter(s[j]))
		{
			ret[i] = s[j];
			ret[j] = s[i];
			i++;
			j--;
		}
		//���ǰ�ߵ��ַ���Ԫ���ַ�������ߵ��ַ����ڿ����λ��
		else if (VowelCharacter(s[i]))
		{
			ret[j] = s[j];
			j--;
		}
		//�����ߵ��ַ���Ԫ���ַ�����ǰ�ߵ��ַ�����ָ����λ��
		else if (VowelCharacter(s[j]))
		{
			ret[i] = s[i];
			i++;
		}
		//�������������Ԫ���ַ�����ǰ�ߵ��ַ����ڿ�ǰ��λ�ã�����ַ����ڿ����λ��
		else
		{
			ret[i] = s[i];
			i++;
			ret[j] = s[j];
			j--;
		}
	}
	//���i��j��ȣ�˵����ʱi��λ��ΪԪ���ַ�����i���ڵ�i��λ����
	if (i == j)
	{
		ret[i] = s[i];
	}
	return ret;
}
int main()
{
	printf("%s\n",reverseVowels("a."));
	return 0;
}