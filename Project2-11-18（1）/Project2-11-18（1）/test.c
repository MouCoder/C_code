#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//ע�������Ӵ��Ķ�������Ǿ���ʹ�õ��Ӵ��Ķ��岻ͬ
	//��֪��Ҫ������ַ��ĸ��������ֻ�ܸ������ֵ���ж���
	char str[8000];
	scanf("%s", str);
	//ע�⣺���ѭ����ʹ��str�����������޷�����str++�����������Ҫ����һ��ָ��
	char* p = str;
	//�ҵ�H�ж�Hǰ���м���C���ҵ�N�ж�ǰ���м���CHN������CHN���ܸ��������Ӵ�����
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